#include"../Header/ScaleMatix.h"

Matrix3x3 MakeScaleMatrix(Vector2 scale) {

    Matrix3x3 result = {};

    result.m[0][0] = scale.x;
    result.m[1][0] = 0.0f;
    result.m[2][0] = 0.0f;

    result.m[0][1] = 0.0f;
    result.m[1][1] = scale.y;
    result.m[2][1] = 0.0f;

    result.m[0][2] = 0.0f;
    result.m[1][2] = 0.0f;
    result.m[2][2] = 1.0f;

    return (result);
};