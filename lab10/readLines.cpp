#include "stabbingLines.h"

void readLines(ifstream& inputLineFile, Line linesArray[], const int MaxLnsSize, int numLines){
    int i=0;
    while(!inputLineFile.eof()){
        Line newl;
        inputLineFile>>newl.Lid>>newl.p1>>newl.p2;
        linesArray[i]=newl;
        i++;   
    }
}
