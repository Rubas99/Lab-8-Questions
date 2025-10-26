#include <stdio.h>

int main() {
    int arr[3][3][3], i = 0, j = 0, k = 0, sum = 0, min = 0, max = 0;
    float count = 0;

    printf("\nEnter elements for the 3x3x3 array\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            for (k = 0; k < 3; k++)
                scanf("%d", &arr[i][j][k]);

    for (i = 0; i < 3; i++) {
        printf("\nLayer #%d\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++)
                printf("%d ", arr[i][j][k]);
            printf("\n");
        }
    }

    for (i = 0; i < 3; i++) {
        sum = 0;
        count = 0;
        max = arr[i][0][0];
        min = arr[i][0][0];
        for (j = 0; j < 3; j++)
            for (k = 0; k < 3; k++) {
                sum += arr[i][j][k];
                count++;
                if (arr[i][j][k] > max) max = arr[i][j][k];
                if (arr[i][j][k] < min) min = arr[i][j][k];
            }
        printf("\nSum of layer #%d = %d", i + 1, sum);
        printf("\nAverage of layer #%d = %.3f", i + 1, (float)sum / count);
        printf("\nLargest element of layer #%d = %d", i + 1, max);
        printf("\nSmallest element of layer #%d = %d\n", i + 1, min);
    }

    sum = 0;
    count = 0;
    max = arr[0][0][0];
    min = arr[0][0][0];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            for (k = 0; k < 3; k++) {
                sum += arr[i][j][k];
                count++;
                if (arr[i][j][k] > max) max = arr[i][j][k];
                if (arr[i][j][k] < min) min = arr[i][j][k];
            }

    printf("\nSum of all layers = %d", sum);
    printf("\nAverage of all layers = %.3f", (float)sum / count);
    printf("\nLargest element of all layers = %d", max);
    printf("\nSmallest element of all layers = %d\n", min);

    return 0;
}

