# Use ccache+clang++ so compilation doesn't take 5 years
ifdef CACHEDCC
CPPC=ccache clang++
else
CPPC=g++
endif

CFLAGS=-std=c++11 -g
SOURCES=Word.cpp Sentence.cpp Paragraph.cpp Story.cpp Main.cpp

OBJ=Word.o Sentence.o Paragraph.o Story.o Main.o

OUTPUT=prog1


all:	linker
	echo $(SOURCES)

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