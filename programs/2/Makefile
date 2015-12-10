CPPC=g++

CFLAGS=-std=c++11 -g -Wall -Wextra
SOURCES=Time.cpp Song.cpp Songs.cpp Radio.cpp HashHeap.cpp Main.cpp

OBJ=Time.o Song.o Songs.o HashHeap.o Radio.o Main.o

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
	echo "RUN in.txt" | ./prog2

clean:
	rm *.o $(OUTPUT)
