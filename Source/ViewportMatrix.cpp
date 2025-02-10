#include"../Header/ViewportMatrix.h"

//ビューポート行列作成関数
Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height) {
    //引数はスクリーン空間上でNDCがどこにどこの大きさで見えるかというのを指定する。

    //ビューポート変換
    Matrix3x3 result = {};
    result.m[0][0] = width / 2.0f;
    result.m[1][0] = 0.0f;
    result.m[2][0] = left + (width / 2.0f);

    result.m[0][1] = 0.0f;
    result.m[1][1] = -height / 2.0f;
    result.m[2][1] = top + (height / 2.0f);

    result.m[0][2] = 0.0f;
    result.m[1][2] = 0.0f;
    result.m[2][2] = 1.0f;

    return result;
}
