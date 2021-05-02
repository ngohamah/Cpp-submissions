#include "blocks.h"

//sorting cylinders in ascending order.
//surface area of cylinders is proportional to the diameters so, sorting by the 
//diameters still provides the same results as sorting with the surface area.

void sortCylinders(vector<cylindricalBlocks> &_cylindricalBlocks){
    sort(_cylindricalBlocks.begin(), _cylindricalBlocks.end(), [](cylindricalBlocks a, cylindricalBlocks b){
    return a.diameter<b.diameter; //sorting in ascending order.
    });
}
    