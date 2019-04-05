lastfiction: main buildarea
	g++ -std=c++17 -Wall main.o buildarea.o -o lastfiction
main: main.cpp
	g++ -c main.cpp
buildarea: buildarea.cpp buildarea.h
	g++ -c buildarea.cpp
clean:
	rm *.o lastfiction