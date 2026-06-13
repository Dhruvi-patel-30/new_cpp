#include <stdio.h>

int main() {
    int a[10][10], b[10][10];
    int row, col, i, j;

    printf("Enter row and column: ");
    scanf("%d %d", &row, &col);

    printf("Enter elements:\n");

    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            b[j][i] = a[i][j];
        }
    }

    printf("\nTranspose of matrix:\n");

    for(i = 0; i < col; i++) {
        for(j = 0; j < row; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}