# This is the Makefile for creating the executable and test program

# This is the g++ compiler
CXX = g++

# This is the compiler links
CXXLINKS = -g -Wall -Wextra -Wpedantic

# This is the compiler flag
CXXFLAG = -c

# This are the objects dependencies file
OBJS = program.o vehicle.o motorcycle.o car.o van.o

# Produce the executable
.PHONY: all
all : execute

execute : main.cpp $(OBJS)
	@echo "---------------------------------------"
	@echo "Creating the executable for the program"
	@echo "---------------------------------------"
	$(CXX) $(CXXLINKS) -o $@ $^

# Produce the test
.PHONY: test
test : testing

testing: testing.cpp $(OBJS)
	$(CXX) $(CXXLINKS) -o $@ $^

%.o : %.cpp
	@echo "---------------------------------------"
	@echo "Compiling the file $<"
	@echo "---------------------------------------"
	$(CXX) $(CXXLINKS) $(CXXFLAG) $<

# For clean up
.PHONY : clean 
clean :
	@echo "---------------------------------------"
	@echo "Clean up $<"
	@echo "---------------------------------------"
	$(RM) *.o
	$(RM) execute
	$(RM) testing

# Dependencies chains
program.o 	: program.cpp program.h
motorcycle.o: motorcycle.cpp motorcycle.h
car.o		: car.cpp car.h
van.o		: van.cpp van.h
vehicle.o	: vehicle.cpp vehicle.h




