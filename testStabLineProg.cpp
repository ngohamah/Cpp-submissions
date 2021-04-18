#include "stabbingLines.h"

using namespace std;

int main(){
    
    ifstream infile1("lines.txt");
    ifstream infile2("points.txt");

    int numLines;
    cout<<"What is the number of lines in file (lines.txt): ";
    cin>>numLines;

    Line linesArray[numLines]; //array is initially empty

    //updating linesArray...
    readLines(infile1, linesArray,1,numLines);

    int numPoints;
    cout<<"What is the number of points in file (points.txt): ";
    cin>>numPoints;
    Point pointsArray[numPoints]; //array is initially empty.
    
    //updating pointsArray...
    readPoints(infile2,pointsArray,1,numPoints); //MaxPntsSize not really relevant for this task.

    int i=0; //line id, for looping through linesArray

    //printing the coordinates of the lines in the linesArray
    while(i<numLines){
        printLineByCoords(i,linesArray,1,pointsArray,1);
        i++;
    }

    //specify xcoord to stab.
    int xcoord;
    cout<<"Specify xcoord used for stabbing: ";
    cin>> xcoord;

    int numOfStabbedLines =0; //by default, this value is zero.

    Line stabbedLines[numLines]; //stabbedLines cannot exhit the total number of lines.

    getStabbedLines(xcoord,linesArray,1,numLines,pointsArray,1,stabbedLines,1,numOfStabbedLines);

}