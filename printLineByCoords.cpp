#include "stabbingLines.h"

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