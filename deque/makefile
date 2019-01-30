all: main_deque main_rand Palindrome Subset main_rand.o main_deque.o Subset.o Palindrome.o

main_deque: main_deque.o deque.h
	g++ -o main_deque main_deque.o deque.h

main_rand: main_rand.o randomized_queue.h
	g++ -o main_rand main_rand.o randomized_queue.h

Palindrome: deque.h Palindrome.o
	g++ -o Palindrome deque.h Palindrome.o

Subset: randomized_queue.h Subset.o
	g++ -o Subset randomized_queue.h Subset.o

main_deque.o: main_deque.cpp deque.h
	g++ -c main_deque.cpp

main_rand.o: main_rand.cpp randomized_queue.h
	g++ -c main_rand.cpp

Subset.o: Subset.cpp
	g++ -c Subset.cpp

Palindrome.o: Palindrome.cpp
	g++ -c Palindrome.cpp
	
clean:
	rm *.o