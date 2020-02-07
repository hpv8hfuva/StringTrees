#Hunter Vaccaro
#hpv8hf
#Lab Section 11:00 am
CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -std=c++11
DEBUG = -Wall -g
.SUFFIXES: .o .cpp

BinarySearchTree: BinaryNode.o BinarySearchTree.o BSTPathTest.o
	$(CXX) $(DEBUG) BinaryNode.o BinarySearchTree.o BSTPathTest.o 

BinaryNode.o: BinaryNode.cpp BinaryNode.h
	$(CXX) -c BinaryNode.cpp

BinarySearchTree.o: BinaryNode.cpp BinaryNode.h BinarySearchTree.h BinarySearchTree.cpp
	$(CXX) -c BinarySearchTree.cpp

BSTPathTest.o: BinarySearchTree.h BinarySearchTree.cpp BSTPathTest.cpp 
	$(CXX) -c BSTPathTest.cpp

clean:
	-rm *.o *~ BinarySearchTree.exe
