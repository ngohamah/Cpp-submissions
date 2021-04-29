#include "stabbingLines.h"

void readPoints(ifstream& inPutPointFile, Point pointsArray[], const int MaxPntsSize, int& numPoints){
    int i=0,c=1;
    while(c<=numPoints){
        Point newp;
        inPutPointFile>>newp.Pid>>newp.x>>newp.y;
        pointsArray[i]=newp;
        i++; c++;      
    }
}
