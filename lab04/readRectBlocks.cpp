#include "blocks.h"

void readRectBlocks(ifstream &inputBlockFile, vector<rectBlocks> &v){
    int w, h, l;
    while(!inputBlockFile.eof()){
        inputBlockFile>>w>>h>>l;
        rectBlocks rb(w,h,l);
        v.push_back(rb);
    }
}