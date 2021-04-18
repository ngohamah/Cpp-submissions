#declaring variables 
CC = g++

DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)

OBJS = testStabLineProg.o readPoints.o readLines.o printLineByCoords.o getStabbedLines.o

#alternative to the all command.
testStabLineProg: $(OBJS) 
	  	  $(CC) $(OBJS) -o testStabLineProg
	  	  
testStabLineProg.o: stabbingLines.h testStabLineProg.cpp
	  	  $(CC) $(CFLAGS) testStabLineProg.cpp	
	  	  
readPoints.o: stabbingLines.h readPoints.cpp
	      $(CC) $(CFLAGS) readPoints.cpp
	     
readLines.o: stabbingLines.h readLines.cpp
	      $(CC) $(CFLAGS) readLines.cpp
	
printLineByCoords.o: stabbingLines.h printLineByCoords.cpp
	      $(CC) $(CFLAGS) printLineByCoords.cpp

getStabbedLines.o: stabbingLines.h getStabbedLines.cpp
	      $(CC) $(CFLAGS) getStabbedLines.cpp

clean: 
	rm -rf *.o testStabLineProg
	


