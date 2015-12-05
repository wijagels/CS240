CPPC=g++

CFLAGS=-std=c++11 -g
SOURCES=Main.cpp

OBJ=Main.o

OUTPUT=Lab8


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
	./$(OUTPUT) in.txt

clean:
	rm *.o $(OUTPUT)
