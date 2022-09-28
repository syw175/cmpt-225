all: fsrs

fsrs: FitStudioReg.o List.o Member.o
	g++ -std=c++11 -Wall -o fsrs FitStudioReg.o List.o Member.o

FitStudioReg.o: FitStudioReg.cpp List.h Member.h
	g++ -std=c++11 -Wall -c FitStudioReg.cpp

List.o: List.h List.cpp
	g++ -std=c++11 -Wall -c List.cpp

Member.o: Member.h Member.cpp
	g++ -std=c++11 -Wall -c Member.cpp

clean:
	rm -f fsrs *.o
