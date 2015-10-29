
# Here's the flag for C++11 support and a flag asking to be warned about
# everything.
CXX = g++
FLAGS = -Wall -std=c++11 -g

all: Lab5 Lab5T

Lab5: Lab5.o Sorter.o
	$(CXX) $(FLAGS) Lab5.o Sorter.o -o Lab5

Sorter.o: Sorter.cpp Sorter.h
	$(CXX) $(FLAGS) -c Sorter.cpp -o Sorter.o

Lab5.o: Lab5.cpp Sorter.h
	$(CXX) $(FLAGS) -c Lab5.cpp -o Lab5.o

Lab5T: Lab5T.o TSorter.o
	$(CXX) $(FLAGS) Lab5T.o TSorter.o -o Lab5T

TSorter.o: TSorter.cpp TSorter.h
	$(CXX) $(FLAGS) -c TSorter.cpp -o TSorter.o

Lab5T.o: Lab5T.cpp TSorter.h TSorter.cpp
	$(CXX) $(FLAGS) -c Lab5T.cpp -o Lab5T.o

test: Lab5T Lab5
	echo "---------Begin Lab5T---------"
	./Lab5T
	echo "---------Begin Lab5---------"
	./Lab5

clean:
	rm -f *.o Lab5 Lab5T

