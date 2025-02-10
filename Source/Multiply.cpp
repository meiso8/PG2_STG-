
#include"../Header/Multiply.h"

Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2) {

    Matrix3x3 result;

    for (int y = 0; y < 3; ++y) {

        for (int x = 0; x < 3; ++x) {

            result.m[y][x] =
                matrix1.m[y][0] * matrix2.m[0][x] +
                matrix1.m[y][1] * matrix2.m[1][x] +
                matrix1.m[y][2] * matrix2.m[2][x];

        }
    }

    return result;
};
