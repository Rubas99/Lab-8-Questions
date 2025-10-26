#include <stdio.h>

int main() {
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0, i = 0, j = 0, k = 0, x = 0, y = 0, z = 0, m1[5][5], m2[5][5], res[5][5], t[5][5], neg[5][5], nonZero = 0, isSquare = 0, isIdentity = 1, isDiagonal = 1, isScalar = 1, upperTri = 1, lowerTri = 1, isSymmetric = 1, isSkew = 1, idempotent = 1, nilpotent = 1, det = 0, equal = 1;

    int minor5[4][4], minor4[3][3], minor3[3][3];

    printf("Enter number of rows for the matrix:\n");
    scanf("%d", &r1);
    if (r1 < 1 || r1 > 5) { printf("number of rows should be greater than 0 and less than or equal to 5"); return 0; }

    printf("Enter number of columns for the matrix:\n");
    scanf("%d", &c1);
    if (c1 < 1 || c1 > 5) { printf("number of columns should be greater than 0 and less than or equal to 5"); return 0; }

    printf("\nEnter elements for the %dx%d matrix:\n", r1, c1);
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &m1[i][j]);

    printf("\nYour matrix\n");
    for (i = 0; i < r1; i++) { for (j = 0; j < c1; j++) printf("%d ", m1[i][j]); printf("\n"); }

    printf("\nDimensions: %dx%d", r1, c1);
    if (r1 == c1) { printf("\nis a square matrix\n"); isSquare = 1; } 
    else { printf("\nis a rectangular matrix\n"); }

    printf("\nzero matrix:\n");
    for (i = 0; i < r1; i++) { for (j = 0; j < c1; j++) printf("0"); printf("\n"); }

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            if (m1[i][j] != 0) nonZero = 1;

    printf("\nYour matrix is %s zero matrix/null matrix\n", nonZero ? "not a" : "a");

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            if (!isSquare || (i == j && m1[i][j] != 1) || (i != j && m1[i][j] != 0)) isIdentity = 0;

    printf("\nYour matrix is %s an identity matrix\n", isIdentity ? "" : "not");

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            if (!isSquare || (i != j && m1[i][j] != 0)) isDiagonal = 0;

    printf("\nYour matrix is %s a diagonal matrix\n", isDiagonal ? "" : "not");

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            if (!isSquare || !isDiagonal || ((i == j && m1[0][0] != m1[i][j]) || (i != j && m1[i][j] != 0))) isScalar = 0;

    printf("\nYour matrix is %s a scalar matrix\n", isScalar ? "" : "not");

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            if (!isSquare || (i > j && m1[i][j] != 0)) upperTri = 0;

    printf("\nYour matrix is %s an upper triangular matrix\n", upperTri ? "" : "not");

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            if (!isSquare || (i < j && m1[i][j] != 0)) lowerTri = 0;

    printf("\nYour matrix is %s a lower triangular matrix\n", lowerTri ? "" : "not");

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            t[j][i] = m1[i][j];

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            if (t[i][j] != m1[i][j]) isSymmetric = 0;

    printf("\nYour matrix is %s symmetric\n", isSymmetric ? "" : "not");

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            neg[i][j] = -m1[i][j];

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            if (!isSquare || neg[i][j] != t[i][j] || (i == j && m1[i][j] != 0)) isSkew = 0;

    printf("\nYour matrix is %s skew-symmetric\n", isSkew ? "" : "not");

    if (r1 != c1) printf("Matrix does not have a determinant\n"); 
    else {
        if (r1 == 1) det = m1[0][0];
        else if (r1 == 2) det = m1[0][0] * m1[1][1] - m1[0][1] * m1[1][0];
        else if (r1 == 3) det = m1[0][0]*(m1[1][1]*m1[2][2]-m1[1][2]*m1[2][1])-m1[0][1]*(m1[1][0]*m1[2][2]-m1[1][2]*m1[2][0])+m1[0][2]*(m1[1][0]*m1[2][1]-m1[1][1]*m1[2][0]);
        printf("\nthe determinant is %d\n", det);
        printf("\nMatrix is %s\n", det == 0 ? "singular" : "non-singular");
    }

    printf("\nEnter number of rows for the second matrix:\n");
    scanf("%d", &r2);
    if (r2 < 1 || r2 > 5) { printf("\nnumber of rows should be greater than 0 and less than or equal to 5\n"); return 0; }
    printf("\nEnter number of columns for the second matrix:\n");
    scanf("%d", &c2);
    if (c2 < 1 || c2 > 5) { printf("\nnumber of columns should be greater than 0 and less than or equal to 5\n"); return 0; }

    printf("\nEnter elements for the %dx%d matrix:\n", r2, c2);
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &m2[i][j]);

    printf("\nYour second matrix\n");
    for (i = 0; i < r2; i++) { for (j = 0; j < c2; j++) printf("%d ", m2[i][j]); printf("\n"); }

    if (r1 != r2 || c1 != c2) equal = 0;
    else for (i = 0; i < r1; i++) for (j = 0; j < c1; j++) if (m1[i][j] != m2[i][j]) equal = 0;

    printf("\nMatrices are %s equal\n", equal ? "" : "not");

    printf("\n\t\tBack to the original matrix\n");
    printf("\nMatrix is %s row matrix\n", r1 == 1 ? "" : "not");
    printf("\nMatrix is %s column matrix\n", c1 == 1 ? "" : "not");

    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++) {
            res[i][j] = 0;
            for (k = 0; k < c1; k++) res[i][j] += m1[i][k] * m1[k][j];
            if (res[i][j] != m1[i][j]) idempotent = 0;
        }

    printf("\nYour matrix is %s an idempotent matrix\n", idempotent ? "" : "not");

    nilpotent = 1;
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            if (res[i][j] != 0) nilpotent = 0;

    printf("\nYour matrix is %s a nilpotent matrix\n", nilpotent ? "" : "not");

    return 0;
}

