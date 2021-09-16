#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "grid.h"
#include "chase.h"
using namespace std;



int main()
{
    int key;
    int down = 0;
    int right = 0;

    int preDown = 0;
    int preRight = 0;
    
    
    readFileInMatrix();
    printMatrix(0, 0);

    while(true){
        getch();
        key = getch();
        preDown = down;
        preRight = right;

        if (key == 77){
            if (right < COL ){
                right++;
            }
        }
        else if (key == 75){
            if (right > 0){
                right--;
            }
        }
        else if (key == 80){
            if (down < ROW){
                down++;
            }
        }
        else if (key == 72){
            if (down > 0){
                down--;
            }
        }
        else if (key == 3){
            exit(1);
        }

        if (path[down][right] == 1){
            down = preDown;
            right = preRight;
        }
        
        populateChaseM(down, right);
        realChaseUP(&downU, &rightU);
        printMatrix(down, right);
        printf("\n\n %d, %d \n", downU, rightU);
    }

    return 0;

}

