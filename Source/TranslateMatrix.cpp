#include"../Header/TranslateMatrix.h"

//平行移動作成関数
Matrix3x3 MakeTranslateMatrix(Vector2 rectCenter) {

    Matrix3x3 result = {};

    result.m[0][0] = 1.0f;
    result.m[1][0] = 0.0f;
    result.m[2][0] = rectCenter.x;

    result.m[0][1] = 0.0f;
    result.m[1][1] = 1.0f;
    result.m[2][1] = rectCenter.y;

    result.m[0][2] = 0.0f;
    result.m[1][2] = 0.0f;
    result.m[2][2] = 1.0f;

    return (result);
};
