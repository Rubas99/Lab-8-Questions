#include <stdio.h>

int main() {
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0, i = 0, j = 0, k = 0, mat1[3][3], mat2[3][3], res[3][3];

    printf("Enter number of rows for the first matrix:\n");
    scanf("%d", &r1);
    if (r1 > 3 || r1 < 1) {
        printf("number of rows should be greater than 0 and less than or equal to 3");
        return 0;
    }
    printf("Enter number of columns for the first matrix:\n");
    scanf("%d", &c1);
    if (c1 > 3 || c1 < 1) {
        printf("number of columns should be greater than 0 and less than or equal to 3");
        return 0;
    }

    printf("\nEnter elements for the first %dx%d matrix:\n", r1, c1);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter number of rows for the second matrix:\n");
    scanf("%d", &r2);
    if (r2 > 3 || r2 < 1) {
        printf("number of rows should be greater than 0 and less than or equal to 3");
        return 0;
    }
    printf("Enter number of columns for the second matrix:\n");
    scanf("%d", &c2);
    if (c2 > 3 || c2 < 1) {
        printf("number of columns should be greater than 0 and less than or equal to 3");
        return 0;
    }

    printf("\nEnter elements for the second %dx%d matrix:\n", r2, c2);
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("\nFirst matrix\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("\nSecond matrix\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    if (c1 != r2) {
        printf("\nMatrix multiplication not possible\n");
        return 0;
    }

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (k = 0; k < c1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("\nFirst matrix x Second matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}

