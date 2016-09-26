main_tests.out: user.o tests.o
	g++ -std=c++11 -Wall user.o tests.o main.cpp -o main_tests.out

user.o: user.h user.cpp
	g++ -std=c++11 -Wall -c user.cpp

tests.o: tests.h tests.cpp
	g++ -std=c++11 -Wall -c tests.cpp

run: main_tests.out
	./main_tests.out

clean:
	rm -f *.o *.out User_Data.dat
