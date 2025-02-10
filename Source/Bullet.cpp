#include"../Header/Bullet.h"
#include"../Header/TranslateMatrix.h"
#include"../Header/Transform.h"
#include"../Header/DiagonalMatrix.h"
#include"../Header/Enemy.h"
#include"../Header/Length.h"

#include<Novice.h>

int Bullet::coolTime_ = 0;

Bullet::Bullet() {

    Init();

};

void Bullet::Init() {

    radius_ = 16.0f;
    worldPos_ = { -radius_, -radius_ };
    worldMatrix_ = DiagonalMatrix1();;
    screenPos_ = Transform({ 0.0f,0.0f }, worldMatrix_);
    velocity_ = { 16.0f,16.0f };
    coolTime_ = 0;
    isShot_ = false;

};

void Bullet::Update(Enemy* enemy) {

    if (isShot_) {

        worldPos_.x += velocity_.x;

        if (worldPos_.x > 1280.0f) {
            isShot_ = false;
        }

        if (!enemy->GetIsHit()) {
            for (int i = 0; i < BULLET_MAX; ++i) {

                if (Length(
                    { worldPos_.x - enemy->GetPosX(),worldPos_.y - enemy->GetPosY() }) <= radius_ + enemy->GetRadius()) {
                    enemy->SetIsHit(true);
                    isShot_ = false;
                }
            }

        }

        worldMatrix_ = MakeTranslateMatrix(worldPos_);
        screenPos_ = Transform({ 0.0f,0.0f }, worldMatrix_);

    }

};

void Bullet::Draw() const {

    if (isShot_) {

        Novice::DrawEllipse(
            static_cast<int>(screenPos_.x),
            static_cast<int>(screenPos_.y),
            static_cast<int>(radius_),
            static_cast<int>(radius_),
            0.0f,
            RED,
            kFillModeSolid
        );
    }

}