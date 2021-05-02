#declaring variables 
CC = g++

DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)

OBJS = testBlockProg.o readRectBlocks.o createBlocks.o sortSpheres.o surfaceOfSphere.o volumeOfSphere.o displaySpheres.o sortCylinders.o surfaceOfCylinder.o displayCylinders.o 

#alternative to the all command.
testBlockProg: $(OBJS) 
	  	  $(CC) $(OBJS) -o testBlockProg
	  	  
readRectBlocks.o: blocks.h readRectBlocks.cpp
	  	  $(CC) $(CFLAGS) readRectBlocks.cpp	
	  	  
createBlocks.o: blocks.h createBlocks.cpp
	  	  $(CC) $(CFLAGS) createBlocks.cpp
	  	  	
sortSpheres.o: blocks.h sortSpheres.cpp
	  	  $(CC) $(CFLAGS) sortSpheres.cpp
	  	  	
surfaceOfSphere.o: blocks.h surfaceOfSphere.cpp
	  	  $(CC) $(CFLAGS) surfaceOfSphere.cpp	
	  	  
volumeOfSphere.o: blocks.h volumeOfSphere.cpp
	  	  $(CC) $(CFLAGS) volumeOfSphere.cpp	

displaySpheres.o: blocks.h displaySpheres.cpp
	  	  $(CC) $(CFLAGS) displaySpheres.cpp	

sortCylinders.o: blocks.h sortCylinders.cpp
	  	  $(CC) $(CFLAGS) sortCylinders.cpp

surfaceOfCylinder.o: blocks.h surfaceOfCylinder.cpp
	  	  $(CC) $(CFLAGS) surfaceOfCylinder.cpp

displayCylinders.o: blocks.h displayCylinders.cpp
	  	  $(CC) $(CFLAGS) displayCylinders.cpp
	  	   	 	  	 
clean: 
	rm -rf *.o testBlockProg
	


