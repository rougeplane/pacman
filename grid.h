#include <iostream>
#include <conio.h>
#include <fstream>
#include <math.h>
#include <sstream>
#include <stdlib.h>

using namespace std;
#define ROW 20
#define COL 20

int path[ROW][COL];
void readFileInMatrix() {
    int i;
    FILE *fp = fopen("Grid.txt", "r");
    if (fp == NULL) {
        cout << "\n File not found\n";
        return;
    }
    for (int row=0; row < ROW; row++) {
        for (int col=0; col < COL; col++) {
            fscanf(fp, "%d ", &path[row][col]);
        }
        fscanf(fp,"\n");
    }
}

void printMatrix(int down, int right) {
    static int score = 0;
    
    system("CLS");
    for (int row=0; row < ROW; row++) {
        for (int col=0; col < COL; col++) {
            if(down == row && right == col){
                if (path[row][col] == 0) {
                    path[row][col] = 2;
                    score++;
                   
                } 
                 cout << "P ";
                 
            }
            else if (path[row][col] == 0){
                cout << ". ";
            }
            else if (path[row][col] == 1){
                cout << "| ";
            }
            else if (path[row][col] == 2){
                cout << "  ";
            }
        }

        cout << "\n";
    }

    cout << "\n\n\n\t\tScore=" << score << endl;

}
/*int main(){

    readFileInMatrix();
    printMatrix(-1, -1);    
}*/

