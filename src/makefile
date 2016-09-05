user.o: user.h user.cpp
	g++ -Wall -c user.cpp

tests.o: tests.h tests.cpp
	g++ -Wall -c tests.cpp

main_tests.out: user.o tests.o
	g++ -Wall -g user.o tests.o main.cpp -o main_tests.out

test: main_tests.out
	./main_tests.out

clean:
	rm -f *.o *.out User_Data.dat
