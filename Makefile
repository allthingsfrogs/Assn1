a.out: main.o matrix.o
	g++ main.o matrix.o

main.o: main.cpp matrix.hpp
	g++ -c -std=c++20 main.cpp

matrix.o: matrix.cpp matrix.hpp
	g++ -c -std=c++20 matrix.cpp

clean: 
	rm -f *.o core a.out
