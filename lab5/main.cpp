#include <iostream>

const int N = 4;

void reverse(float *matrix, float *vectB, int k, int r) {
    float c;
    for (int j = k; j < N; j++) {
        c = matrix[k + j * N];
        matrix[k + j * N] = matrix[r + j * N];
        matrix[r + j * N] = c;
    }
    c = vectB[k];
    vectB[k] = vectB[r];
    vectB[r] = c;
}

void divide(float *matrix, float *vectB, int k) {
    for (int j = k + 1; j < N; j++) {
        matrix[k + j * N] /= matrix[k + k * N];
    }
    vectB[k] /= matrix[k + k * N];
}

void clear(float *matrix, float *vectB, int k, int r) {
    for (int j = k + 1; j < N; j++) {
        matrix[r + j * N] -= matrix[k + j * N] * matrix[r + k * N];
    }
    vectB[r] -= vectB[k] * matrix[r + k * N];
}

int main() {
    float *matrix;
    float *vectB;
    float vectX[N];
    int i, j, k;

    matrix = new float[N * N] {
            -0.77, -0.60,  -0.55,  -1.83,
            0.62,  -0.99,  2.90,  -0.11,
            -2.31,  -0.05,  3.41, -0.82,
            -0.46,-1.49,  -1.47,  3.54
    };

    /*

     */

    vectB = new float[N] {
            1.14,8.69,9.41,5.81
    };

    for (k = 0; k < N - 1; k++) {
        if (matrix[k + k * N] == 0) {
            i = k + 1;
            while(matrix[i + k * N] == 0) {
                i++;
            }
            reverse(matrix, vectB, k, i);
        }
        divide(matrix, vectB, k);
        for (i = k + 1; i < N; i++) {
            clear(matrix, vectB, k, i);
        }
    }
    divide(matrix, vectB, N - 1);

    for (int D = 0; D < N; D++) {
        for (int G = 0; G < N; G++) {
            std::cout << " " << matrix[G + D * N] << " ";
        }
        std::cout << std::endl;
    }

    for (i = N - 1; i >= 0; i--) {
        vectX[i] = vectB[i];
        for (j = i + 1; j < N; j++) {
            vectX[i] -= matrix[i + j * N] * vectX[j];
        }
        std::cout << "x(" << i + 1 << ") = " << vectX[i] << std::endl;
    }
    return 0;
}