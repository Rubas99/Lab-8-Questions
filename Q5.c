#include <stdio.h>

int main() {
    int arr[3][3][3], a = 0, b = 0, c = 0, firstSecondDiff = 0, firstThirdDiff = 0, secondThirdDiff = 0;

    printf("\nEnter elements for the 3x3x3 array\n");
    for (a = 0; a < 3; a++)
        for (b = 0; b < 3; b++)
            for (c = 0; c < 3; c++)
                scanf("%d", &arr[a][b][c]);

    for (a = 0; a < 3; a++) {
        printf("\nLayer #%d\n", a + 1);
        for (b = 0; b < 3; b++) {
            for (c = 0; c < 3; c++)
                printf("%d ", arr[a][b][c]);
            printf("\n");
        }
    }

    for (b = 0; b < 3; b++)
        for (c = 0; c < 3; c++) {
            if (arr[0][b][c] != arr[1][b][c]) firstSecondDiff = 1;
            if (arr[0][b][c] != arr[2][b][c]) firstThirdDiff = 1;
            if (arr[1][b][c] != arr[2][b][c]) secondThirdDiff = 1;
        }

    if (firstSecondDiff == 0)
        printf("First layer and second layer are the same\n");
    else
        printf("First layer and second layer are distinct\n");

    if (firstThirdDiff == 0)
        printf("First layer and third layer are the same\n");
    else
        printf("First layer and third layer are distinct\n");

    if (secondThirdDiff == 0)
        printf("Second layer and third layer are the same\n");
    else
        printf("Second layer and third layer are distinct\n");

    return 0;
}

