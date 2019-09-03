all: graph.o prog.exe clean
prog.exe: main.cpp graph.o 
	g++ -std=c++11 -o prog main.cpp graph.cpp
graph.o: graph.cpp
	g++ -std=c++11 -c graph.cpp
clean: 
	-rm *.o