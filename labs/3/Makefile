CPPC=clang++
CFLAGS=-std=c++11
SOURCES=Bank.cpp Customer.cpp
OBJ=Bank.o Customer.o
OUTPUT=Bank
#
# Specifiy the target
all:	linker
	echo $(SOURCES)

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
linker: gen_obj
	$(CPPC) $(CFLAGS) $(OBJ) -o $(OUTPUT)

# Specify how the object files should be created from source files
gen_obj: $(SOURCES)
	$(CPPC) $(CFLAGS) -c $(SOURCES)

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm *.o $(OUTPUT)
