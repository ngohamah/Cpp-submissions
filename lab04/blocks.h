#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>
#define PI 3.14159

using namespace std;

/*Classes*/

class rectBlocks
{
    public: 
        int width, height, length;

        rectBlocks(){
            width=0;
            height=0;
            length=0;
        }

        rectBlocks(int w, int h, int l) { 
            width = w;
            height = h;
            length = l;
        }   
};

class sqrBaseRectBlocks: public rectBlocks{
    public:
        sqrBaseRectBlocks(){
            width = 0;
            height = 0;
            length = 0;
        } 
        
        // width = height
        sqrBaseRectBlocks(int w, int l){
            width = w;
            height = w;
            length = l;
        }   
};

class cuboidBlocks: public sqrBaseRectBlocks{
      public:
        cuboidBlocks(){
            width =0;
            height =0;
            length = 0;
        }
        
        //w = h = l
        cuboidBlocks(int w){
            width = w;
            height = w;
            length = w;
        }  
};

class cylindricalBlocks: public sqrBaseRectBlocks{

      public:
        int diameter;

        //d = w or h
        cylindricalBlocks(int d,int l){
            diameter=d;
            length=l;
        } 
};

class sphericalBlocks: public cuboidBlocks{
    public: 
        int diameter;

        sphericalBlocks(int d){
            diameter=d;
        }
};

/*Functions*/

//note: unlike arrays, vectors must be defined as being passed by reference.
//inputBlockFile is passed by reference to enable the object hold the data beyond this function.
void readRectBlocks(ifstream &inputBlockFile, vector<rectBlocks> &v); 
void createBlocks(vector<rectBlocks> &_rectBlocks, vector<sqrBaseRectBlocks> &_sqrBaseRectBlocks, 
    vector<cuboidBlocks> &_cuboidBlocks, vector<cylindricalBlocks> &_cylindricalBlocks, 
    vector<sphericalBlocks> &_sphericalBlocks);
void sortSpheres(vector<sphericalBlocks> &_sphericalBlocks);
double surfaceOfSphere(int diameter);
double volumeOfSphere(int diameter);
void displaySpheres(const vector<sphericalBlocks> &_sphericalBlocks);
void sortCylinders(vector<cylindricalBlocks> &_cylindricalBlocks);
double  surfaceOfCylinder(int diameter, int length);
void displayCylinders(const vector<cylindricalBlocks> &_cylindricalBlocks);




