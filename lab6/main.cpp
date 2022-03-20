#include <iostream>

const int N = 4;

float teta(float *matrix) {
    float t, s;
    t = 0;
    for (int i = 0; i < N; i++) {
        s = 0;
        for (int j = 0; j < N; j++) {
            s += std::abs(matrix[i + j * N]);
            std::cout << "S = " << s << std::endl;
        }
        s /= std::abs(matrix[i + i * N]);
        if (t < s) {
            t = s;
        }
    }
    return t - 1;
}

float norma(float *vectX, float *vectY) {
    float s, d;
    d = 0;
    for (int  i = 0; i < N; i++) {
        s = std::abs(vectX[i] - vectY[i]);
        if (s > d) {
            d = s;
        }
    }
    return d;
}

void step(float *vectX, float *vectY, float *matrix, float *vectB) {
    for (int i = 0; i < N; i++) {
        vectY[i] = -vectB[i];
        for (int j = 0; j < N; j++) {
            vectY[i] += matrix[i + j * N] * vectX[j];
        }
        vectY[i] = vectX[i] - vectY[i] / matrix[i + i * N];
    }
}

void prowerka(float *vectX2, float *matrix, float *vectB) {
    float s;
    for (int i = 0; i < N; i++) {
        s = 0;
        for (int j = 0; j < N; j++) {
            s += matrix[i + j * N] * vectX2[j];
        }
        std::cout << s << " " << vectB[i] << std::endl;
    }
}

int main() {
    float *matrix;
    float *vectB;
    float *vectX;
    float *vectX2;
    float accuracy, t;

    accuracy = 0.0001f;

    matrix = new float[N * N] {
            -15.12, -4.02,  -1.04,  2.26,
            2.06,  -13.89,  -4.93,  0.58,
            3.48,  -1.87,  13.48, 3.78,
            -3.58,2.74,  3.11,  -8.33
    };

    vectB = new float[N] {
            -14.74,-47.62,-65.22,29.92
    };

    vectX = new float[N];
    vectX2 = new float[N];

    t = teta(matrix);
    std::cout << "Teta= " << t << std::endl;
    for (int  i = 0; i < N; i++) {
        vectX2[i] = 0;
    }

    while(true) {
        for (int i = 0; i < N; i++) {
            vectX[i] = vectX2[i];
        }

        step(vectX, vectX2, matrix, vectB);
        if (norma(vectX, vectX2) <= (accuracy * (1 - t) / t)) break;
    }

    for (int i = 0; i < N; i++) {
        std::cout << "x(" << i << ")= " << vectX2[i] << std::endl;
    }

    prowerka(vectX2, matrix, vectB);
    return 0;
}