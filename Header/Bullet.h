#pragma once

#include "Vector2.h"
#include"Matrix3x3.h"

class Enemy;

#define BULLET_MAX 10

class Bullet {
public:
    float radius_;
    Vector2 worldPos_;
    Matrix3x3 worldMatrix_;
    Vector2 screenPos_;
    Vector2 velocity_;

    static int coolTime_;
    bool isShot_;
public:

    Bullet();
    void Init();
    void Update(Enemy* enemy);

    void Draw() const;

};
