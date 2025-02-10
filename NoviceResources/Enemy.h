#pragma once
#include"Vector2.h"

class Enemy
{
private:
    Vector2 size_;

    Vector2 localLeftTop_;
    Vector2 localRightTop_;
    Vector2 localLeftBottom_;
    Vector2 localRightBottom_;

    float theta_;
    Vector2 scale_;
    Vector2 worldPos_;

    Vector2 screenLeftTop_;
    Vector2 screenRightTop_;
    Vector2 screenLeftBottom_;
    Vector2 screenRightBottom_;

public:
    Enemy();
    void Init();
    void Update();
    void Draw();
};

