#include "blocks.h"

using namespace std;

int main(){    

    ifstream in; 
    in.open("dataBlocks.dat");
    vector<rectBlocks> v1;

    //reading rectBlock file.
    readRectBlocks(in, v1);

    //creating various blocks types.
    vector<sqrBaseRectBlocks> v_sbrb;
    vector<cuboidBlocks> v_cub;
    vector<cylindricalBlocks> v_cyb;
    vector<sphericalBlocks> v_sb;

    createBlocks(v1, v_sbrb, v_cub,v_cyb,v_sb);  

    //sorting sphericalBlocks vector: v_sb
    sortSpheres(v_sb);

    //display sphericalBlocks
    displaySpheres(v_sb);

    //sorting cylindricalBlocks vector: v_cyb
    sortCylinders(v_cyb);

    //display cylindricalBlocks 
    displayCylinders(v_cyb);

    in.close();
    cin.get();
}