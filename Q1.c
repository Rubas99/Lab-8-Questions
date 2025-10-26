#include <stdio.h>

int main() {
     int r = 3, c = 3, m[3][3], x = 0, y = 0, d, mn[2][2], i1 = 0, j1 = 0, cf[3][3], sg, p1 = 0, q1 = 0, adj[3][3];

    printf("Enter elements of a 3x3 matrix:\n");
    for (x = 0; x < r; x++) {
        for (y = 0; y < c; y++) {
            scanf("%d", &m[x][y]);
        }
    }

    printf("\nThe transpose matrix is:\n");
    for (y = 0; y < c; y++) {
        for (x = 0; x < r; x++) {
            printf("%d\t ", m[x][y]);
        }
        printf("\n");
    }

    d = m[0][0] * ((m[1][1] * m[2][2]) - (m[1][2] * m[2][1])) 
      - m[0][1] * ((m[1][0] * m[2][2]) - (m[1][2] * m[2][0])) 
      + m[0][2] * ((m[1][0] * m[2][1]) - (m[1][1] * m[2][0]));

    printf("\nThe determinant is: %d\t\n", d);
    if (d == 0) {
        printf("Matrix has no inverse.\n");
        return 0;
    }

    for (i1 = 0; i1 < 3; i1++) {
        for (j1 = 0; j1 < 3; j1++) {
            p1 = 0;
            q1 = 0;
            for (x = 0; x < 3; x++) {
                for (y = 0; y < 3; y++) {
                    if (x != i1 && y != j1) {
                        mn[p1][q1] = m[x][y];
                        q1++;
                        if (q1 == 2) {
                            q1 = 0;
                            p1++;
                        }
                    }
                }
            }
            if ((i1 + j1) % 2 == 0) {
                sg = 1;
            } else {
                sg = -1;
            }
            cf[i1][j1] = sg * (mn[0][0] * mn[1][1] - mn[0][1] * mn[1][0]);
        }
    }

    printf("\nThe cofactor matrix is:\n");
    for (x = 0; x < r; x++) {
        for (y = 0; y < c; y++) {
            printf("%d\t ", cf[x][y]);
        }
        printf("\n");
    }

    printf("\nThe adjoint matrix is:\n");
    for (y = 0; y < c; y++) {
        for (x = 0; x < r; x++) {
            adj[x][y] = cf[x][y];
            printf("%d\t ", adj[x][y]);
        }
        printf("\n");
    }

    printf("\nThe inverse matrix is:\n");
    for (y = 0; y < c; y++) {
        for (x = 0; x < r; x++) {
            printf("%.3f\t ", adj[x][y] / (1 / (float)d));
        }
        printf("\n");
    }

    return 0;
}

