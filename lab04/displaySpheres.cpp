#include "blocks.h"

void displaySpheres(const vector<sphericalBlocks> &_sphericalBlocks){
    
    cout<<endl;
    cout<<"Diameter    "<<"Surface Area      "<<"Volume      "<<endl;
    cout<<"--------    "<<"------------     "<<"-------- "<<endl;
    for(int l=0;l<_sphericalBlocks.size();l++){
        cout<<_sphericalBlocks[l].diameter<<"           "<<surfaceOfSphere(_sphericalBlocks[l].diameter)
        <<"          "<<volumeOfSphere(_sphericalBlocks[l].diameter)<<endl;
    }
}