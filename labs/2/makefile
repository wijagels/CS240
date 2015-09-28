CPPC= g++
#
# Specifiy the target
all:	linker

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
linker: gen_obj
	$(CPPC) JagelsWilliamAccountFunctions.o Lab2.o  -o Bank

# Specify how the object files should be created from source files
gen_obj: JagelsWilliamAccountFunctions.cpp Lab2.cpp
	$(CPPC) -c JagelsWilliamAccountFunctions.cpp Lab2.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm *.o Bank
