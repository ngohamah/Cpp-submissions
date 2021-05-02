#include "blocks.h"

void displayCylinders(const vector<cylindricalBlocks> &_cylindricalBlocks){
    cout<<endl;
    cout<<"Diameter    "<<"Surface Area      "<<"Length      "<<endl;
    cout<<"--------    "<<"------------     "<<"-------- "<<endl;
    for(int p=0;p<_cylindricalBlocks.size();p++){
        cout<<_cylindricalBlocks[p].diameter<<"           "<<
        surfaceOfCylinder(_cylindricalBlocks[p].diameter,_cylindricalBlocks[p].length)
        <<"             "<<_cylindricalBlocks[p].length<<endl;
    }
}   

    