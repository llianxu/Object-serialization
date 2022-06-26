main: main.o tinyxml2.o
	g++ -o main main.o tinyxml2.o

main.o : main.cpp
	g++ -c main.cpp

tinyxml2.o : tinyxml2.cpp
	g++ -c tinyxml2.cpp

clean:
	del main.o tinyxml2.o main.exe *.data *.xml -r
