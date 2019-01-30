all: Register student.o course.o courseSelect.o utility.o record.o

Register: main.cpp student.o course.o courseSelect.o utility.o record.o
	g++ -o Register main.cpp student.o course.o courseSelect.o utility.o record.o

student.o:
	g++ -c student.cpp

course.o:
	g++ -c course.cpp

courseSelect.o:
	g++ -c courseSelect.cpp

utility.o:
	g++ -c utility.cpp

record.o:
	g++ -c record.cpp
	
clean:
	rm *.o


