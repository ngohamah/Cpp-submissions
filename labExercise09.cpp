#include <iostream>
#include <cstdlib>
#include <random>


using namespace std;

/**
 * @brief Creates a 2D integer array and then returns the array.
 * 
 * @param rows 
 * @param cols 
 * @return int** 
 */
int** createIntegerArray2D(int rows, int cols)
{
    int **A = new int*[rows];

    for(int i=0;i<rows;i++){
        A[i]=new int[cols];
    }

    return A;
}


/**
 * @brief This function initializes N numbers of randomly selected i,j pairs using a specified value(valuetoinitialize) 
 * 
 * @param valuetointialize 
 * @param array 
 * @param rows 
 * @param cols 
 * @param N 
 */

void initializeIntegerArray2D(int valuetointialize, int **array, int rows, int cols,int N){

    random_device rd;

    int a;
    int b;
    for(int i=0;i<N;i++)
    {
        //a and b, are randomly selected using the random_device object rd.
        a = rd()%(rows);
        b = rd()%(cols); 
        
        //value to initialize is then initialized to the randomly generated index.
        array[a][b]=valuetointialize;
    }
}


/**
 * @brief deallocates 2D array in memory to free the memory heap.
 * 
 * @param array 
 * @param rows 
 */
void deallocateIntegerArray2D(int **array, int rows){
    
    //deallocating columns
    for(int i=0;i<rows;i++){
        delete[] array[i];
    }

    //delocating rows.
    delete[] array;

    //setting memory to null
    array = NULL;
}


/*

Pseudocode:  func populateArray()

START

-> get 2D array as array
-> get the rows and columns of array as rows, columns
-> get the value that is equal to the user's specified undefinedvalue as undefinedvalue
-> get the number of i,j pairs to be randomly populated as N
-> create integer variables a, and b
-> for i=0, i<N do:
        a= random()%(rows)
        b= random()%(columns)

        if(array[a][b]< undefinedvalue)array[a][b]=1;
        else if(array[a][b]>=undefinedvalue)array[a][b]+=1;

END

*/


/**
 * @brief this function populates a given 2D array by assigning undefined values to randomly selected indices. 
 * 
 * @param N 
 * @param array 
 * @param undefinedvalue 
 * @param rows 
 * @param cols 
 */

void populateArray(int N, int **array, int undefinedvalue, int rows, int cols){
    int a;
    int b;
    random_device rd;

    for(int i=0;i<N;i++){
        a = rd()%(rows);
        b = rd()%(cols); 

        if(array[a][b]<undefinedvalue) array[a][b]=1;
        else if(array[a][b]>=undefinedvalue) array[a][b]+=1;
    }
}



/*

Pseudocode:  func searchValidEntries()

START

-> get 2D array as array
-> gett the x and y coordinates of the lower end of the diagonal as (xl,yl)
-> get the x and y coordinates of the higher end of the diagonal as (xh,yh)
-> create integer variables x, and y and assign them to zero as x=0, y=0
-> create 2D array to store search entries using xh, yh as b:
        b = createIntegerArray2D(xh,yh)

-> for i=xl; i<=xh do:
        for j=yl; j<=yh do:
            b[x][y]=array[i][j]
            y++

        x++
        y=0

-> return b

END

*/


/**
 * @brief Given the coordinates of the ends of a diagonal, searchValidEntries would print the matrix that 
          aligns well with that diagonal as well as the indices of the entries from the original matrix.
 * 
 * @param xl 
 * @param yl 
 * @param xh 
 * @param yh 
 * @param array 
 * @return int** 
 */

void searchValidEntries(int xl, int yl, int xh, int yh, int** array){
    int **b = createIntegerArray2D(xh,yh);

    int x=0;
    int y=0;

    cout<<endl<<endl<<"[";
    for(int i=xl;i<=xh;i++)
    {
        for(int j=yl;j<=yh;j++){
            b[x][y]=array[i][j];
            cout<<"("<<i<<","<<j<<") ";
            y++;
        }
        x++;
        y=0;
    }

    cout<<"]";
    
    cout<<endl<<endl;

    for(int i=0;i<=(xh-xl);i++){
        for(int j=0;j<=(yh-yl);j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}


/**
 * @brief creates, initializes and populates arry and returns the array.
 * 
 * @param rows 
 * @param columns 
 * @param numberofrandompairs_ij 
 * @return int** 
 */
int** initializeAndpopulate(int rows, int columns, int numberofrandompairs_ij){
    
    int **A = createIntegerArray2D(rows,columns); 

    initializeIntegerArray2D(1,A,rows,columns,numberofrandompairs_ij);

    populateArray(numberofrandompairs_ij,A,1,rows, columns); 

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    return A;
}


int main(){

    int** A = initializeAndpopulate(101, 101, 2000);

    /* Displaying bounding boxes of A given,
    
     xl, yl, xh, yh */

    // 80, 1, 100, 10
    searchValidEntries(80, 1, 100, 10,A);

    //10, 20, 40, 79
    searchValidEntries(10, 20, 40, 79,A);

    //1, 90, 100, 100,
    searchValidEntries(1, 90, 100, 100,A);

    //40, 30, 70, 60,
    searchValidEntries(40, 30, 70, 60,A);

    //50, 50, 70, 70
    searchValidEntries(50, 50, 70, 70,A);


    deallocateIntegerArray2D(A, 101);

    cin.get();
}


