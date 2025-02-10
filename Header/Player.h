#pragma once
#include"Bullet.h"

#include"Vector2.h"
#include"Matrix3x3.h"


class Player
{
private:
    Vector2 size_;

    Vector2 leftTop_;
    Vector2 rightTop_;
    Vector2 leftBottom_;
    Vector2 rightBottom_;

    Vector2 screenLeftTop_;
    Vector2 screenRightTop_;
    Vector2 screenLeftBottom_;
    Vector2 screenRightBottom_;

    Vector2 direction_;
    float length_;

    float theta_;
    Vector2 scale_;
    Vector2 velocity_;
    Vector2 worldPos_;
    Matrix3x3 worldMatrix_;

    int graphHandle_;

    Bullet bullet_[BULLET_MAX];
    bool isHit_;
    int respawnTimer_;

public:
    Player();
    ~Player();
    void Init();
    void Update(char(&keys)[256], Enemy* enemy);
    void Move(char(&keys)[256]);
    void Shot(char(&keys)[256]);
    void TransformScreen();

    bool GetIsHit() { return isHit_; };
    float GetPosX() { return worldPos_.x; };
    float GetPosY() { return  worldPos_.y; };
    float GetRadius() { return size_.x / 2.0f; };

    void SetIsHit(bool isHit) { isHit_ = isHit; };

    void Draw() const;
};
