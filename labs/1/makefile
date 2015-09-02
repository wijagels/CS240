#
# Specifiy the target
all:	linker

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
linker: gen_obj
	clang++  *.o  -o Hello

# Specify how the object files should be created from source files
gen_obj:
	clang++ -c *.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Hello
