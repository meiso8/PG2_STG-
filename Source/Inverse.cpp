#include"../Header/Inverse.h"

Matrix3x3 Inverse(Matrix3x3 matrix) {

    float determinant =
        matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] +
        matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] +
        matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1] -
        matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] -
        matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] -
        matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1];

    Matrix3x3 result;

    result.m[0][0] =
        (matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1]) /
        determinant;

    result.m[0][1] =
        (-1.0f *
            (matrix.m[0][1] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][1])) /
        determinant;

    result.m[0][2] =
        (matrix.m[0][1] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][1]) /
        determinant;

    result.m[1][0] =
        (-1.0f *
            (matrix.m[1][0] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][0])) /
        determinant;

    result.m[1][1] =
        (matrix.m[0][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][0]) /
        determinant;

    result.m[1][2] =
        (-1.0f *
            (matrix.m[0][0] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][0])) /
        determinant;

    result.m[2][0] =
        (matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][0]) /
        determinant;

    result.m[2][1] =
        (-1.0f *
            (matrix.m[0][0] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[2][0])) /
        determinant;

    result.m[2][2] =
        (matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0]) /
        determinant;

    return result;
};