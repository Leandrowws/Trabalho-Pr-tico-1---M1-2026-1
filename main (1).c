#include<stdio.h>

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    
    *returnSize = matSize;

    int *diagonal = (int*)malloc(sizeof(int)*matSize);

    int i, j;


    for(i = 0; i < *matColSize; i++) {

        for(j = 0; j <= i; j++) {

        diagonal[i] = mat[i][j];

    }

}


    return diagonal;

}



int main() {

    



    return 0;
}