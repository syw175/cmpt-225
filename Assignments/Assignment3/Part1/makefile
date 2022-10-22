all: td

td: testDriver.o WordPair.o BST.o BSTNode.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o
	g++ -std=c++11 -Wall -o td testDriver.o WordPair.o BST.o BSTNode.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o
	
testDriver.o: testDriver.cpp
	g++ -std=c++11 -Wall -c testDriver.cpp 
		
WordPair.o: WordPair.h WordPair.cpp
	g++ -std=c++11 -Wall -c WordPair.cpp
			
BST.o: BST.h BST.cpp
	g++ -std=c++11 -Wall -c BST.cpp
	
BSTNode.o: BSTNode.h BSTNode.cpp
	g++ -std=c++11 -Wall -c BSTNode.cpp
	
ElementDoesNotExistException.o: ElementDoesNotExistException.h ElementDoesNotExistException.cpp
	g++ -std=c++11 -Wall -c ElementDoesNotExistException.cpp

ElementAlreadyExistsException.o: ElementAlreadyExistsException.h ElementAlreadyExistsException.cpp
	g++ -std=c++11 -Wall -c ElementAlreadyExistsException.cpp
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -std=c++11 -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f td *.o
