#include "blocks.h"

//surface area: 2*PI*r*h + 2*PI*r*r = PI*d*h + (PI*d*d)/2
//where h=length, r=diameter/2
double  surfaceOfCylinder(int diameter, int length){
    return PI*diameter*length + (PI*diameter*diameter)/2;
}