#include <iostream>
#include <conio.h>
#include <fstream>
#include <math.h>
#include <sstream>

using namespace std;

void create_grid(int grid);

int main(){

    const int GRID_SIZE = 20;
    int gridarray [20][20];
    string text;

    ifstream gridr("Grid.txt");

    while (getline (gridr, text)){
        cout << text << endl;
    }
    
}