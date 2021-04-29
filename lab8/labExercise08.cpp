#include <iostream>
#include <cstdlib>
#include <random>


using namespace std;

/**
 * HOW MY CODE WORKS***********
 * 
 * The linearisation functions works (LinearIndx) in a very simple way, 
 * what I wanted to return was the index of the 1 dimensional array where
 * the 2 dimensional element would be placed. So, I drew out a pattern as 
 * below
 * 
 * 2D      1D
 * 
 * 0,0  -> 0
 * 1,0  -> 1
 * 1,1  -> 2
 * 2,0  -> 3
 * ...  .. ..
 * n,n  -> ?
 * 
 * then I realized with the help of some online assistance that actually,
 * the formular that models this kind of relationship is 
 * 
 * (a*(a+1))*0.5 +b where a and b are the i,j coordinates of our multidim.
 * 
 * such that
 * 
 * I = F(i,j)
 *   = (i*(i+1))*0.5 +j
 * 
 * 
 * For the inverse procedure (InverseIndx) which can be written as
 * 
 * (i,j) = F-1(I)
 * 
 * The procedure took a parameter d, and uses d for comparison with an
 * accummulator. 
 * 
 * So basically, my code loops through an arbitrury 2dim while an accumulator,
 * in this case c, counts to see if it has made progress to the position d
 * 
 * If yes, it stores the i, and j coordinates of this iteration into a array
 * pointer which is returned and used to conduct this future operations.
 * 
 * 
 * 
 * 
 */



/**
 * @brief returns the index of the 1dim where the 2dim element would be stored
 * 
 * @param a 
 * @param b 
 * @return int 
 */

int LinearIndx(int a, int b){
    return (a*(a+1))*0.5 +b;
}

/**
 * @brief returns size of a 1dim array that would contain the elements of a 2dim.
 * 
 * @param row 
 * @return int 
 */
int getSizeOfB(int row){
    return (0.5)*(row*row+row);
}


/**
 * @brief returns the indices of the 2dim where the 1dim element would be written into
 * 
 * @param d 
 * @return int* 
 */
int* InverseIndx(int d){
    int c;
    int* indices = (int*) malloc(sizeof(int)*2);
    for(int i=1;i<=d;i++){
        for(int j=0;j<=i;j++){
            c++;
            if(c==d){
                indices[0]=i;
                indices[1]=j;
            }
        }
    }
    return indices;
}

/**
 * @brief Carries out the required activities of the ICP lab_08
 * 
 * @param row 
 * @param numberOfItemsToShow 
 */
void doOperations(int row, int numberOfItemsToShow){
    int a[row][row];

    random_device rd;

    //initializing random values for lower triangular matrix.
    for(int m=0; m<row;m++)
    {
        for(int n=0;n<=m;n++)
        {
            a[m][n]=rd()%1000;
        }
    }
    
    int s=0;
    cout<<"Lower triangular matrix A[][] \n"<<endl;
    for(int e=0;e<row;e++){
        for(int f=0;f<=e;f++){
            s++;
            cout<<a[e][f]<<" ";
            if(s==numberOfItemsToShow) break;
        }
        cout<<endl;
        if(s==numberOfItemsToShow) break;
    }

    cout<<"\nPrinting Indices of A[][] matrix"<<endl;
    s=0;
    for(int e=0;e<row;e++){
        for(int f=0;f<=e;f++){
            s++;
            cout<<"("<<e<<","<<f<<")";
            if(s==numberOfItemsToShow) break;
        }
        if(s==numberOfItemsToShow) break;
    }


    int b[getSizeOfB(row)]; 

    int len_b= sizeof(b)/sizeof(b[0]);

    //assigning 2D elements to 1D    
    for(int i=0;i<row;i++){
        for(int j=0;j<=i;j++){
            int index = LinearIndx(i,j); 
            b[index]=a[i][j];  
        }
    }

    //assigning 1D elements back to 2D
    int arr_c[row][row];
    for(int k=0; k<len_b;k++){
        int* arr= InverseIndx(k);
        int i = arr[0];
        int j = arr[1];

        arr_c[i][j]=b[k];
        free(arr); //to avoid leakage, we need to free the arr pointer.
    }

    cout<<"\n\nFirst "<<numberOfItemsToShow<<" elements of 1 dimensional B[]"<<endl<<"[";
    for(int l=0;l<numberOfItemsToShow;l++){
        cout<<b[l]<<" ";
    }
    cout<<"]"; 

    cout<<"\n\nLower triangular matrix C[][] - first n elements"<<endl;
    int c=0;
    for(int m=0;m<row;m++)
    {
        cout<<"\n";
        for(int n=0;n<=m;n++){
            c++;
            cout<<arr_c[m][n]<<" ";
            if(c==numberOfItemsToShow) break;
        }
        if(c==numberOfItemsToShow) break;
    }

    cin.get(); //to capture blank screen.
}


int main(){ 
    
    int row;
    int n;

    cout<<"Enter the rows of your square matrix: ";
    cin>>row;

    cout<<"Enter the number of element you want to show: ";
    cin>>n;
    
    doOperations(row,n);

    cin.get();
}
