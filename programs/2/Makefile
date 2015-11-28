CPPC=g++

CFLAGS=-std=c++11 -g
SOURCES=Time.cpp Song.cpp Songs.cpp Main.cpp

OBJ=Time.o Song.o Songs.o Main.o

OUTPUT=prog2


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
	echo "RUN test.txt" | ./prog2

optest: gen_obj
	$(CPPC) $(CFLAGS) $(OBJ) testProgram.o -o testProgram

clean:
	rm *.o $(OUTPUT)
