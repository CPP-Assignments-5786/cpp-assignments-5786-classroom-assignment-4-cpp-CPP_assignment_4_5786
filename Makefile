CXX=g++
CXXFLAGS=-std=c++23 -Werror -Wsign-conversion -Wall -Wextra
SOURCES=Grade.cpp Student.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

all: demo
	./demo

demo: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestRunner.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test
	./test

TestRunner.o: test.cpp Grade.hpp Student.hpp doctest.h
	$(CXX) $(CXXFLAGS) --compile test.cpp -o TestRunner.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

Grade.o: Grade.cpp Grade.hpp

Student.o: Student.cpp Student.hpp Grade.hpp

main.o: main.cpp Grade.hpp Student.hpp

clean: 
	rm -f *.o demo test