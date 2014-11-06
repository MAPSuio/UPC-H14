#------------ Folder info
LBIN	= bin
LOBJ	= obj
LSRC	= src

#------------ Compile options
CC		= gcc -g
DEBUG	= -D DEBUG
CFLAGS	= -Wall
EXE		= main
LIBS	= -lrt
OBJ		= $(LOBJ)/main.o \
		  $(LOBJ)/irq.o \
		  $(LOBJ)/network.o 

#----------- Rules
.PHONY: all memcheck clean 


#----------- Makes
all: $(EXE)
	@echo "Everything is compiled. Ready to run!"

# building the exec.
$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(LBIN)/$(EXE) $(LIBS)

# compiling and linking
$(LOBJ)/%.o: $(LSRC)/%.c dirs
	$(CC) $(CFLAGS) $< -c -o $@


debug: CFLAGS+=-DDEBUG
debug: all

#----------- Other functions
dirs:
	mkdir -p obj
	mkdir -p bin


memceck: all
	@echo "Starting valgrind.."
	valgrid ./$(LBIN)/$(EXE)

clean:
	rm -f ./$(LOBJ)/*.o ./$(LBIN)/main
