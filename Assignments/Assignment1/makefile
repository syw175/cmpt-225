all: fsrs

fsrs: FitStudioReg.o List.o Member.o
	g++ -Wall -o fsrs FitStudioReg.o List.o Member.o

FitStudioReg.o: FitStudioReg.cpp List.h Member.h
	g++ -Wall -c FitStudioReg.cpp

List.o: List.h List.cpp
	g++ -Wall -c List.cpp

Member.o: Member.h Member.cpp
	g++ -Wall -c Member.cpp

clean:
	rm -f fsrs *.o
