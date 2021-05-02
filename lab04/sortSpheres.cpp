#include "blocks.h"

void sortSpheres(vector<sphericalBlocks> &_sphericalBlocks){
    sort(_sphericalBlocks.begin(), _sphericalBlocks.end(), [](sphericalBlocks a, sphericalBlocks b){

        return a.diameter<b.diameter; //sorting from the lowest values to the highest values.
    });
    
}