#include <stdio.h>

int main() {
    int a[10][10];
    int row, col;
    int i, j;
    int r, c;
    int rowSum = 0, colSum = 0;

    printf("Enter row size: ");
    scanf("%d", &row);

    printf("Enter column size: ");
    scanf("%d", &col);

    printf("Enter elements:\n");

    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
 
    printf("Enter row number: ");
    scanf("%d", &r);

    for(j = 0; j < col; j++) {
        rowSum += a[r][j];
    }

    printf("Sum of row %d = %d\n", r, rowSum);


    printf("Enter column number: ");
    scanf("%d", &c);

    for(i = 0; i < row; i++) {
        colSum += a[i][c];
    }

    printf("Sum of column %d = %d\n", c, colSum);

}