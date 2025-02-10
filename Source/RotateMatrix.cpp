#include"../Header/RotateMatrix.h"
#include <math.h>

Matrix3x3 MakeRotateMatrix(float theta) {

    Matrix3x3 result = {};

    result.m[0][0] = cosf(theta);
    result.m[1][0] = -sinf(theta);
    result.m[2][0] = 0.0f;

    result.m[0][1] = sinf(theta);
    result.m[1][1] = cosf(theta);
    result.m[2][1] = 0.0f;

    result.m[0][2] = 0.0f;
    result.m[1][2] = 0.0f;
    result.m[2][2] = 1.0f;

    return (result);
};
