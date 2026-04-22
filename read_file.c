#include <stdio.h>
#include <stdlib.h>

extern int sum_array(int *arr, long n);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: No file detected \n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Couldn't open file \n");
        return 1;
    }

    long n;
    if (fscanf(fp, "%ld", &n) != 1 || n < 0) {
        printf("Error: Invalid size \n");
        fclose(fp);
        return 1;
    }

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error: Invalid Size \n");
        fclose(fp);
        return 1;
    }

    for (long i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &arr[i]) != 1) {
            printf("Error: Invalid data \n");
            free(arr);
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    int sum = sum_array(arr, n);
    printf("Sum = %d\n", sum);

    free(arr);
    return 0;
}