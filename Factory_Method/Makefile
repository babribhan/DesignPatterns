main: main.o vehicle.o factory.o
	g++ -std=c++11 -o main main.o vehicle.o factory.o

main.o : main.cpp 
	g++ -std=c++11 -c main.cpp


vehicle.o: vehicle.cpp 
	g++ -std=c++11 -c vehicle.cpp

factory.o: factory.cpp 
	g++ -std=c++11 -c factory.cpp

clean: 
	rm -f main *.o 

