#include"../Header/AffineMatrix.h"
#include<math.h>

//アフィン行列作成関数
Matrix3x3 MakeAffineMatrix(Vector2 scale, float theta, Vector2 translate) {

    Matrix3x3 result = {};

    result.m[0][0] = scale.x * cosf(theta);
    result.m[1][0] = scale.y * -sinf(theta);
    result.m[2][0] = translate.x;

    result.m[0][1] = scale.x * sinf(theta);
    result.m[1][1] = scale.y * cosf(theta);
    result.m[2][1] = translate.y;

    result.m[0][2] = 0.0f;
    result.m[1][2] = 0.0f;
    result.m[2][2] = 1.0f;

    return (result);
};
