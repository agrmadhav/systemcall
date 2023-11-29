#include <stdio.h>
#include <pthread.h>

#define MAX_DIM 10

int matrixA[MAX_DIM][MAX_DIM];
int matrixB[MAX_DIM][MAX_DIM];
int result[MAX_DIM][MAX_DIM];

int m, n, l; // Dimensions of the matrices

void *multiplyRowCol(void *arg) {
    int row = *((int *)arg);

    for (int col = 0; col < l; col++) {
        result[row][col] = 0;
        for (int k = 0; k < n; k++) {
            result[row][col] += matrixA[row][k] * matrixB[k][col];
        }
    }

    pthread_exit(NULL);
}

int main() {
    // Initialize matrices and dimensions

    pthread_t threads[MAX_DIM];
    int rows[MAX_DIM];

    // Create threads for matrix multiplication
    for (int i = 0; i < m; i++) {
        rows[i] = i;
        pthread_create(&threads[i], NULL, multiplyRowCol, (void *)&rows[i]);
    }

    // Join threads
    for (int i = 0; i < m; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display result matrix
    for(int i=0;i<)

    return 0;
}
