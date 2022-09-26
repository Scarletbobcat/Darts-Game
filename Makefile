project1: project1.o fraction.o point.o
	g++ -o project1 main.o fraction.o point.o

project1.o: project1.cc 
	g++ -c project1.cc

fraction.o: fraction.cc fraction.h
	g++ -c fraction.cc

point.o: point.cc point.h
	g++ -c point.cc
