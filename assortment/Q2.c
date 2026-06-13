#include <stdio.h>

int main() {
    int a[10][10], row, col;
    int i, j, max;

    printf("Enter row and column: ");
    scanf("%d %d", &row, &col);

    printf("Enter elements:\n");

    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
           printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    max = a[0][0];

    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            if(a[i][j] > max) {
                max = a[i][j];
            }
        }
    }

    printf("Largest element = %d\n", max);

   
}