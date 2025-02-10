#include "../Header/OrthographicMatrix.h"

Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom) {

    //正規かデバイス座標系
    //NDC

    //引数は左上と右下の座標でカメラ空間上での座標である
    Matrix3x3 result = {};
    result.m[0][0] = 2.0f / (right - left);
    result.m[1][0] = 0.0f;
    result.m[2][0] = (left + right) / (left - right);

    result.m[0][1] = 0.0f;
    result.m[1][1] = 2.0f / (top - bottom);
    result.m[2][1] = (top + bottom) / (bottom - top);

    result.m[0][2] = 0.0f;
    result.m[1][2] = 0.0f;
    result.m[2][2] = 1.0f;

    return result;

}