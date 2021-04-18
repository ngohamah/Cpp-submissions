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

