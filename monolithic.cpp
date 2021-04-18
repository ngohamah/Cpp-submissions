#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <fstream>
#define MAXARRAYSIZE 500

using namespace std;

typedef int PointID;
typedef int LineID;

struct Point{
    PointID Pid;
    int x;
    int y;
};

struct Line{
    LineID Lid;
    PointID p1;
    PointID p2;
};

void readPoints(ifstream& inPutPointFile, Point pointsArray[], const int MaxPntsSize, int& numPoints);
void readLines(ifstream& inputLineFile, Line linesArray[], const int MaxLnsSize, int numLines);
void printLineByCoords(LineID lid, Line linesArray[], const int MaxLnsSize, Point pointsArray[], const int MaxPntsSize);
void getStabbedLines(const int xcoord, Line linesArray[], const int MaxLnsSize, const int NumLines, Point pointsArray[], const int MaxPtsSize, Line stabbedLines[], const int MaxStbSize, int& NumOfStbLines);


void readPoints(ifstream& inPutPointFile, Point pointsArray[], const int MaxPntsSize, int& numPoints){
    int i=0,c=1;
    while(c<=numPoints){
        Point newp;
        inPutPointFile>>newp.Pid>>newp.x>>newp.y;
        pointsArray[i]=newp;
        i++; c++;      
    }
}


void readLines(ifstream& inputLineFile, Line linesArray[], const int MaxLnsSize, int numLines){
    int i=0;
    while(!inputLineFile.eof()){
        Line newl;
        inputLineFile>>newl.Lid>>newl.p1>>newl.p2;
        linesArray[i]=newl;
        i++;   
    }
}


void printLineByCoords(LineID lid, Line linesArray[], const int MaxLnsSize, Point pointsArray[], const int MaxPntsSize){
    //since the lid corresponds to the indices of linesArray[], we can proceed ...
    Line line = linesArray[lid];
    PointID point1 = line.p1;
    PointID point2 = line.p2;

    Point p1 = pointsArray[point1];
    Point p2 = pointsArray[point2];
    
    cout<<endl;
    cout<<"Line "<<line.Lid+1<<" : "<<endl \
        <<"endpoint p1:: "<<"("<<p1.x<<","<<p1.y<<")"<<endl \
        <<"endpoint p2:: "<<"("<<p2.x<<","<<p2.y<<")"<<endl<<endl;
}

void getStabbedLines(const int xcoord, Line linesArray[], const int MaxLnsSize, const int NumLines, \
Point pointsArray[], const int MaxPtsSize, Line stabbedLines[], const int MaxStbSize, \
int& NumOfStbLines){
    int i=0;

    cout<<endl<<"Lines stabbed::: "<<endl<<endl<<"Lids: "<<endl;
    while(i<NumLines){
        Line line = linesArray[i]; //get first line.

        //get the Pid for each line.
        PointID point1 = line.p1; 
        PointID point2 = line.p2;

        //get the endpoints corresponding to the pointIDs above.
        Point p1 = pointsArray[point1]; //end point 1.
        Point p2 = pointsArray[point2]; //end point 2.

        //check if line gets stabbed by xcoord
        if(p1.x<=xcoord && p2.x>=xcoord){
            stabbedLines[i]=line; 
            cout<<stabbedLines[i].Lid<<endl;
            NumOfStbLines++; //updating the reference of the number of stabbed lines.
        }
        i++;
    }  

    cout<<endl<<"Number of lines stabbed by xcoord: "<<NumOfStbLines<<endl<<endl;
}

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