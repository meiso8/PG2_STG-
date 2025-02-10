#pragma once

#include"Vector2.h"
#include"Matrix3x3.h"

class Enemy {
private:

    Vector2 size_;

    Vector2 leftTop_;
    Vector2 rightTop_;
    Vector2 leftBottom_;
    Vector2 rightBottom_;

    Vector2 worldPos_;

    Vector2 screenLeftTop_;
    Vector2 screenRightTop_;
    Vector2 screenLeftBottom_;
    Vector2 screenRightBottom_;

    float theta_;
    Vector2 scale_;
    Vector2 velocity_;

    Matrix3x3 worldMatrix_;

    int graphHandle_;

    int respawnTimer_;

    bool isHit_;
    bool isDraw_;

public:
    Enemy();
    void Init();
    void Update();
    void TransformScreen();

    bool GetIsHit() { return isHit_; };
    float GetPosX() const { return worldPos_.x; };
    float GetPosY() const { return  worldPos_.y; };
    float GetRadius() const { return size_.x / 2.0f; };

    void SetIsHit(bool isHit) { isHit_ = isHit; };

    void Draw();
};