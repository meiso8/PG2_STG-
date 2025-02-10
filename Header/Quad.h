#pragma once
#include"Vector2.h"
#include"Matrix3x3.h"

//矩形の構造代を作ろうとしたが無理だった

struct Quad {
    Vector2 leftTop_;
    Vector2 rightTop_;
    Vector2 leftBottom_;
    Vector2 rightBottom_;
};

Quad MakeLocalQuad(Vector2& size);

Quad MakeScreenQuad(Quad& local, Matrix3x3& worldMatrix);
