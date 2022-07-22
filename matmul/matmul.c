#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define DIMS 256
#define SIZE DIMS * sizeof(1.0)

// Currently its a square matrix
#define rowsA DIMS
#define colsA DIMS
#define rowsB DIMS
#define colsB DIMS

float A[SIZE][SIZE];
float B[SIZE][SIZE];
float C[SIZE][SIZE];

void matmul() {
    /*
    Arguably the simplest possible way to do matrix multiplication.
    There are much faster implementations out there.
    */
    size_t i, j, k;
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            for (k = 0; k < rowsB; k++) {
                C[i][j] += B[k][j] * A[j][k];
            }
        }
    }
}

float rand_float(float a) {
    /*
    returns a random float between 0.0 and a
    */
    float f = ((float)rand()/(float)(RAND_MAX)) * a;
    return f;
}

void random_fill() { 
    size_t i, j;
    for (i = 0; i < DIMS; i++){
        for (j = 0; j < DIMS; j++) {
            float temp_val = rand_float(10.0);
            A[i][j] = temp_val; 
        }
    }

    for (i = 0; i < DIMS; i++){
        for (j = 0; j < DIMS; j++) {
            float temp_val = rand_float(10.0);
            B[i][j] = temp_val; 
        }
    }
    
    for (i = 0; i < DIMS; i++){
        for (j = 0; j < DIMS; j++) {
            float temp_val = rand_float(10.0);
            C[i][j] = temp_val; 
        }
    }
}





int main() {
    printf("Multiplying a %u x %u matrix:\n",DIMS,DIMS);
    int i = 0;
    random_fill();
    clock_t t0, tf;
    double times[sizeof(1.0)*5];
    int iter = 5;
    while (i < iter){
        t0 = clock();
        matmul();
        tf = clock();
        double elap = (double)(tf - t0)/CLOCKS_PER_SEC;
        times[i] = elap;
        printf("Elapsed time = %.4lf s\n",elap);
        i++; 
    }

    double mean_time;
    for (i = 0; i < iter; i++) {
        mean_time += times[i];
    }
    mean_time = mean_time/iter;
    printf("Mean = %.4f s\n",mean_time);

    return 0;
}