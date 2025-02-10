#include"../Header/Transform.h"
#include <math.h>
#include<assert.h>

//ベクトル変換
Vector2 Transform(Vector2 pos, Matrix3x3 worldMatrix) {
    Vector2 result = {};
    result.x = pos.x * worldMatrix.m[0][0] + pos.y * worldMatrix.m[1][0] +
        1.0f * worldMatrix.m[2][0];

    result.y = pos.x * worldMatrix.m[0][1] + pos.y * worldMatrix.m[1][1] +
        1.0f * worldMatrix.m[2][1];

    float w = pos.x * worldMatrix.m[0][2] + pos.y * worldMatrix.m[1][2] +
        1.0f * worldMatrix.m[2][2];

    assert(w != 0.0f); // 0だったらプログラムを終了する
    result.x /= w;
    result.y /= w;

    return (result);
};
