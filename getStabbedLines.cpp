#include "stabbingLines.h"

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