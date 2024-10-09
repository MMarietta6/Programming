#include <stdio.h>

#define ROW 9

int main() {
    int n;
    printf("Enter the number of columns in matrix A: ");
    scanf("%d", &n);

    int A[ROW][n];
    int i, j;
    long long int product[n]; // to store the product of negative elements for each column

    // initialize product array to 1
    for (i = 0; i < n; i++) {
        product[i] = 1;
    }

    // input matrix A
    printf("Enter elements of matrix A:\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // calculate product of negative elements for each column
    for (j = 0; j < n; j++) {
        for (i = 0; i < ROW; i++) {
            if (A[i][j] < 0) {
                product[j] *= A[i][j];
            }
        }
    }

    // print the product of negative elements for each column
    for (j = 0; j < n; j++) {
        if (j < 8) {
            printf("Product of negative elements in column %d: %lld\n", j + 1, product[j]);
        }
    }

    return 0;
}
