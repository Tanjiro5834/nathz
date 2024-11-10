#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 6

void rotateMatrix(int matrix[ROWS][COLS]);

int main(){
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30}
    };
    rotateMatrix(matrix);
    
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void rotateMatrix(int matrix[ROWS][COLS]){
    for(int i = 0; i < ROWS - 1; i++){
        for(int j = i; j < COLS - 1; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for(int i = 0; i < ROWS; i++){
        int start = 0;
        int end = ROWS - 1;
        while (start < end) {
            int temp = matrix[i][start];
            matrix[i][start] = matrix[i][end];
            matrix[i][end] = temp;
            start++;
            end--;
        }
    }
}