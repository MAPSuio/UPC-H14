#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <zlib.h>

#define BLOCKSIZE (1024*1024)

typedef struct farray_t farray;
typedef struct file_t file;

struct farray_t {
	file *files;
	size_t count;
	size_t allocated;
};
struct file_t {
	char          *file;
	size_t        size;
	char          hassum;
	unsigned long sum;
};
void file_getsum(file *f){
	unsigned char buf[BLOCKSIZE];
	unsigned int crc = crc32(0, Z_NULL, 0);
	FILE *fp = fopen(f->file,"rb");
	size_t read;
	if(!fp)
		return;
	f->sum = 0;
	//crc = ~crc;
	fprintf(stderr, "Checksum of %s: ", f->file);
	while (!feof(fp) && !ferror(fp)){
		read = fread(&buf, 1, sizeof(buf), fp);
		if(read == 0) break;
		crc = crc32(crc, (void *)&buf, read);
	}
	fprintf(stderr, "%x\n", crc);

	f->sum = crc;

	if(!ferror(fp))
		f->hassum=1;
	fclose(fp);
}

int file_compare(const void *ap, const void *bp){
	file *a=(file *)ap, *b=(file *)bp;
	if     (a->size > b->size) return  1;
	else if(b->size > a->size) return -1;
	// Equal sizes
	if(!a->hassum){
		file_getsum(a);
	}
	if(!b->hassum){
		file_getsum(b);
	}
	if(b->hassum && a->hassum){
		if     (a->sum > b->sum) return 1;
		else if(b->sum > a->sum) return -1;
	}
	return 0;
}

farray *farray_init(){
	farray *t = malloc(sizeof(farray));
	t->count     = 0;
	t->allocated = 0;
	t->files     = NULL;
	return t;
}
void farray_destroy(farray *this){
	size_t i=0;
	for(i=0;i<this->count;i++){
		free(this->files[i].file);
	}
	free(this->files);
	free(this);
}
void farray_allocate(farray *this, size_t min){
	size_t new = 1;
	if(this->allocated >= min)
		return;
	if(this->allocated > 0)
		new = this->allocated*2;
	while(min > new)
		new = new*2;
	// (re)allocate new*sizeof(file)
	if(!this->files)
		this->files = malloc(sizeof(file)*new);
	else
		this->files = realloc(this->files, sizeof(file)*new);
	this->allocated = new;
	fprintf(stderr, "Array resize: %lu items, (>=) %lu KB \n", new, (sizeof(file)*new)/1024);
}
void farray_push(farray *this, const char *path, size_t size){
	farray_allocate(this, this->count+1);
	this->files[this->count].file   = strdup(path);
	this->files[this->count].size   = size;
	this->files[this->count].hassum = 0;
	this->count += 1;
}
void farray_sort(farray *this){
	fprintf(stderr, "Sorting...\n");
	qsort(this->files, this->count, sizeof(file), file_compare);
	fprintf(stderr, "Sort complete\n");
}
void farray_print(farray *this){
	size_t i;
	const char *prev=NULL;
	size_t prevs;
	unsigned long prevsum;
	file *p;
	for(i=0;i<this->count;i++){
		p = &this->files[i];
		if(prev != NULL && prevs == p->size && prevsum == p->sum){
			printf("%s\n", p->file);
		}
		prev    = p->file;
		prevs   = p->size;
		prevsum = p->sum;
	}
}

void recurse_path(const char *path, farray *f){
	// Might be a file, might be a dir
	struct stat statd;
	int ret;
	DIR *d;
	struct dirent * dir_ent, de;
	char *tmp;
	ret = lstat(path, &statd);
	if(ret != 0){
		printf("Error:     %s\n", path);
		return;
	}
	if(S_ISDIR(statd.st_mode)){
		//printf("Directory: %s\n", path);
		d = opendir(path);
		if(!d){
			printf("Cannot opendir() %s\n", path);
			return;
		}
		while((dir_ent = readdir(d))){
			memcpy(&de, dir_ent, sizeof(struct dirent));
			if(de.d_type & DT_DIR &&
			   (!strcmp(de.d_name, ".") ||
			    !strcmp(de.d_name, "..")))
				continue;
			tmp = malloc(strlen(path)+strlen(de.d_name)+2);
			tmp[0] = 0;
			strcat(tmp,path);
			strcat(tmp,"/");
			strcat(tmp,de.d_name);
			recurse_path(tmp, f);
			free(tmp);
		}
		closedir(d);
	} else if(S_ISREG(statd.st_mode)){
		//printf("File:      %s\n", path);
		farray_push(f, path, statd.st_size);
	} else {
		printf("Irregular: %s\n", path);
	}
}

int main(int argc, char **argv){
	int i;
	farray *f;
	if(argc < 2){
		printf("USAGE: %s <path> [path] ... [path]\n", argv[0]);
		return 1;
	}
	f = farray_init();
	for(i=1;i<argc;i++){
		recurse_path(argv[i], f);
	}
	farray_sort(f);
	farray_print(f);

	return 0;
}
