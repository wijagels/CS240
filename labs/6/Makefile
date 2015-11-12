CPPC=g++

CFLAGS=-std=c++11 -g
SOURCES=BinarySearchTree.cpp Node.cpp Timing.cpp

OBJ=BinarySearchTree.o Node.o Timing.o

OUTPUT=lab6


all:	linker

linker: gen_obj
	$(CPPC) $(CFLAGS) $(OBJ) -o $(OUTPUT)

# Build object files one by one to
# take advantage of caching
gen_obj: $(SOURCES)
	for file in $(SOURCES); do\
		$(CPPC) $(CFLAGS) -c $$file;\
	done

test: linker
	valgrind ./$(OUTPUT)

clean:
	rm *.o $(OUTPUT)
