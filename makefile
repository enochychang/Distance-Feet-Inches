a.out : main.o Distance.o
	g++ main.o Distance.o

main.o : main.cpp Distance.h
	g++ -Wall -c main.cpp

Distance.o : Distance.cpp Distance.h
	g++ -Wall -c distance.cpp

clean : 
	rm *.o a.out
