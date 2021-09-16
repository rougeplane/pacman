#include "grid.h"
#include "chase.h"



int main(){
    readFileInMatrix();
    populateChaseM(11, 12);
    printarr();

    std::cout << "\n\n\n\n";

    populateChaseM(19, 18);
    printarr();

    return 0;
}