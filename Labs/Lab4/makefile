all: lab4

lab4: Lab4App.o Queue.o Member.o EmptyDataCollectionException.o
	g++ -o lab4 Lab4App.o Queue.o Member.o EmptyDataCollectionException.o

# Note, this makefile is very strong in terms of dependencies.
# It assumes most classes can depend on others, just to be safe.
# This results in much redundant compilation, and one could remove some of these dependencies.

Lab4App.o: Lab4App.cpp Queue.h Member.h EmptyDataCollectionException.h
	g++ -c Lab4App.cpp
	
Queue.o: Queue.cpp Queue.h Member.h EmptyDataCollectionException.h
	g++ -c Queue.cpp

Member.o: Member.cpp Member.h
	g++ -c Member.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c EmptyDataCollectionException.cpp

clean:
	rm -f lab4 *.o
