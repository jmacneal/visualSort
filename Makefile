SHELL = /bin/sh
LIBS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
CC = g++ -std=c++11 -Wall -Iinclude
objects = main.o rectangle.o
includes = $(wildcard include/*.h)

test : $(objects) ${includes}
	$(CC) -o test $(objects) $(LIBS)

main.o : main.cpp constants.h rectangle.h sort.h ${includes}
	$(CC) -c -o main.o main.cpp

rectangle.o : rectangle.cpp rectangle.h constants.h ${includes}
	$(CC) -c -o rectangle.o rectangle.cpp

clean : 
	rm test $(objects)
