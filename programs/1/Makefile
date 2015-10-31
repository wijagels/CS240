CPPC=g++

CFLAGS=-std=c++11 -g
SOURCES=Word.cpp Sentence.cpp Paragraph.cpp Story.cpp Aux.cpp Main.cpp testProgram.cpp

OBJ=Word.o Sentence.o Paragraph.o Story.o Aux.o

OUTPUT=prog1


all:	linker

linker: gen_obj
	$(CPPC) $(CFLAGS) $(OBJ) Main.o -o $(OUTPUT)

# Build object files one by one to
# take advantage of caching
gen_obj: $(SOURCES)
	for file in $(SOURCES); do\
		$(CPPC) $(CFLAGS) -c $$file;\
	done

test: linker
	valgrind ./$(OUTPUT)
	diff fp.txt ./STORIES/FreshPrince.txt
	diff br.txt ./STORIES/Brady.txt
	diff gi.txt ./STORIES/Gilligan.txt

optest: gen_obj
	$(CPPC) $(CFLAGS) $(OBJ) testProgram.o -o testProgram
	./testProgram

clean:
	rm *.o $(OUTPUT) testProgram
