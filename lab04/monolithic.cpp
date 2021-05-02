#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>
#define PI 3.14159

using namespace std;

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


/*functions to compute the surface areas and volume*/


//surface area: 2*PI*r*h + 2*PI*r*r = PI*d*h + (PI*d*d)/2
//where h=length, r=diameter/2
double  surface_cylinder(int diameter, int length){
    return PI*diameter*length + (PI*diameter*diameter)/2;
}

//surface: 4*pi*r*r = pi * d * d

double surface_sphere(int diameter){
    return PI*diameter*diameter;
}

//volume: pi*d*d*d*(1/6)
double volume_sphere(int diameter){
    return (PI*diameter*diameter*diameter)/6;
}



int main(){
    
    int w, h, l;

    ifstream in; 
    in.open("dataBlocks.dat");

    vector<rectBlocks> v1;

    while(!in.eof()){
        in>>w>>h>>l;
        rectBlocks rb(w,h,l);
        v1.push_back(rb);
    }

    /*Generating the various block arrays*/

    vector<sqrBaseRectBlocks> v_sbrb;
    vector<cuboidBlocks> v_cub;
    vector<cylindricalBlocks> v_cyb;
    vector<sphericalBlocks> v_sb;


    for(int i=0; i<v1.size(); i++){
        int w = v1[i].width;
        int h = v1[i].height;
        int l = v1[i].length;

        if(w==h){

            //assigning members to sqrBaseRectBlocks vector
            sqrBaseRectBlocks _sbrb(w,l);
            v_sbrb.push_back(_sbrb);

            //assigning members to cylindricalBlocks vector
            cylindricalBlocks _cyb(w,l);
            v_cyb.push_back(_cyb);

            //assigning members to cubiodBlocks vector
            if(h==l){
                cuboidBlocks _cub(w);
                v_cub.push_back(_cub);

                //assigning members to the sphericalBlock vector
                sphericalBlocks _sb(w);
                v_sb.push_back(_sb);
            }
        }

    }


    //sorting sphericalBlocks array: v_sb
    sort(v_sb.begin(), v_sb.end(), [](sphericalBlocks a, sphericalBlocks b){

        return a.diameter<b.diameter; //sorting from the lowest values to the highest values.
    });

    //printing the diameter, surface and volume of the spheres

    cout<<endl;
    cout<<"Diameter    "<<"Surface Area      "<<"Volume      "<<endl;
    cout<<"--------    "<<"------------     "<<"-------- "<<endl;
    for(int l=0;l<v_sb.size();l++){
        cout<<v_sb[l].diameter<<"           "<<surface_sphere(v_sb[l].diameter)
        <<"          "<<volume_sphere(v_sb[l].diameter)<<endl;
    }
    

    //sorting cylinders in ascending order.
    //surface area of cylinders is proportional to the diameters so, sorting by the 
    //diameters still provides the same results as sorting with the surface area.
    sort(v_cyb.begin(), v_cyb.end(), [](cylindricalBlocks a, cylindricalBlocks b){

        return a.diameter<b.diameter; //sorting in ascending order.
    });
    
    //printing the diameter, cylindrical surface area and length of cylinders

    cout<<endl;
    cout<<"Diameter    "<<"Surface Area      "<<"Length      "<<endl;
    cout<<"--------    "<<"------------     "<<"-------- "<<endl;
    for(int p=0;p<v_cyb.size();p++){
        cout<<v_cyb[p].diameter<<"           "<<surface_cylinder(v_cyb[p].diameter,v_cyb[p].length)
        <<"             "<<v_cyb[p].length<<endl;
    }

    in.close();
    cin.get();

}