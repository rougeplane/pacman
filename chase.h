#ifndef CHASE_H
#define CHASE_H 

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "const.h"




/* ----------------------------------------------------------------
* this function populates chase matrix. Input of the function is the current position
of pacman.
-------------------------------------------------------------------*/
void populateChaseM(int row, int col){
    int n = 1;
    chase[row][col] = 0;


    for (int i = 0; i < ROW; i++){

        for (int j = 0; j < COL; j++){
           chase[i][j] =  std::max(abs((row - i)), abs((col - j)));
           
           if (path[i][j] == 1) {
               chase[i][j] = 30;
           }
        }
    }
}


/*
* This function moves a ghost to its new location. 
* Input of this function is the current location of the ghost.
*/
void realChaseUP(int *row, int *col) {
    //row-1, col //UP
    //row+1, col //DOWN
    //row, col+1 //right
    //row, col-1 //left
    int mRow = *row-1, mCol=*col;
    int min = chase[*row-1][*col]; // default is up as it is uppy
    if (chase[*row+1][*col] < min){ // down
        mRow = *row+1;
        mCol=*col;
        min = chase[*row+1][*col]; 
    } else if(chase[*row][*col+1] < min){ //right
        mRow = *row;
        mCol = *col+1;
        min = chase[*row][*col+1];
    } else if(chase[*row][*col-1] < min){ //left
        mRow = *row;
        mCol = *col-1;
        min = chase[*row][*col-1];
    } 

    *row = mRow;
    *col = mCol;
}

void printarr(){
    for (int i = 0; i < ROW; i++){

        for (int j = 0; j < COL; j++){
            std::cout << chase[i][j] << " ";
        }
        std::cout << std::endl;
    }
}



#endif