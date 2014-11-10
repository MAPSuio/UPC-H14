#ifndef LOG_H
#define LOG_H


#define GREEN  "\x1B[32m"
#define BLUE  "\x1B[34m"
#define CYAN  "\x1B[36m"
#define RED  "\x1B[31m"

/* Other colors */
#define KNRM  "\x1B[0m"
#define KYEL  "\x1B[33m"
#define KMAG  "\x1B[35m"
#define KWHT  "\x1B[37m"


#define _ERR(...) do { \
	fprintf(stderr, "" BLUE "%17s:" GREEN "%-4d - " CYAN "%-25s" RED "## ERROR ##: " \
			KWHT, __FILE__, __LINE__, __FUNCTION__); \
	fprintf(stderr, ##__VA_ARGS__); \
	fprintf(stderr, "\n\n"); \
} while (0);


#ifdef DEBUG
#define _DEBUG(...) do { \
    fprintf(stderr, BLUE "%17s:" GREEN "%-4d - " CYAN "%-25s" \
            KWHT, __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stderr, ##__VA_ARGS__); \
    fprintf(stderr, "\n"); \
} while (0);
#else
	#define _DEBUG(...)
#endif

#endif
