benchmark.out: user.o tests.o benchmark.cpp
	g++ -std=c++11 -Wall user.o tests.o benchmark.cpp -o benchmark.out

main_tests.out: user.o tests.o
	g++ -std=c++11 -Wall user.o tests.o main.cpp -o main_tests.out

user.o: user.h user.cpp
	g++ -std=c++11 -Wall -c user.cpp

tests.o: tests.h tests.cpp
	g++ -std=c++11 -Wall -c tests.cpp

run: benchmark.out
	./benchmark.out

clean:
	rm -f *.o *.out User_Data.dat
