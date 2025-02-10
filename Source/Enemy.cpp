#include"../Header/Enemy.h"
#include"../Header/Transform.h"

#include"../Header/TranslateMatrix.h"
#include"../Header/DiagonalMatrix.h"
#include<Novice.h>

#ifdef _DEBUG
#include<imgui.h>
#endif // _DEBUG
//自動移動
//リスポーン処理

Enemy::Enemy() {

    graphHandle_ = Novice::LoadTexture("./NoviceResources/white1x1.png");

    Init();
}


void Enemy::Init() {

    size_ = { 32.0f,32.0f };

    leftTop_ = { -size_.x / 2.0f,-size_.y / 2.0f };
    rightTop_ = { size_.x / 2.0f,-size_.y / 2.0f };
    leftBottom_ = { -size_.x / 2.0f,size_.y / 2.0f };
    rightBottom_ = { size_.x / 2.0f,size_.y / 2.0f };


    worldPos_ = { 1280.0f - 64.0f,360.0f };

    theta_ = 0.0f;
    scale_ = { 1.0f,1.0f };
    velocity_ = { 16.0f,16.f };

    worldMatrix_ = DiagonalMatrix1();

    TransformScreen();

    respawnTimer_ = 120;

    isHit_ = false;

}

void Enemy::Update() {

    if (!isHit_) {

        worldPos_.y += velocity_.y;

        if (worldPos_.y < 0.0f || worldPos_.y > 720.0f) {
            velocity_.y *= -1.0f;
        }
    }

    if (isHit_) {

        if (respawnTimer_ > 0) {
            respawnTimer_--;
        } else {
            Init();
        }

        isDraw_ = (respawnTimer_ % 2 == 0) ? true : false;

    }

    worldMatrix_ = MakeTranslateMatrix(worldPos_);

    TransformScreen();

#ifdef _DEBUG

    ImGui::Begin("Enemy");
    ImGui::SliderFloat2("pos", &worldPos_.x, 0.0f, 1280.0f);

    ImGui::Text("isHit %d", isHit_);
    ImGui::End();

#endif // _DEBUG

}

void Enemy::TransformScreen() {

    screenLeftTop_ = Transform(leftTop_, worldMatrix_);
    screenRightTop_ = Transform(rightTop_, worldMatrix_);
    screenLeftBottom_ = Transform(leftBottom_, worldMatrix_);
    screenRightBottom_ = Transform(rightBottom_, worldMatrix_);

}

void Enemy::Draw() {

    if (isDraw_) {

        Novice::DrawQuad(
            static_cast<int>(screenLeftTop_.x),
            static_cast<int>(screenLeftTop_.y),
            static_cast<int>(screenRightTop_.x),
            static_cast<int>(screenRightTop_.y),
            static_cast<int>(screenLeftBottom_.x),
            static_cast<int>(screenLeftBottom_.y),
            static_cast<int>(screenRightBottom_.x),
            static_cast<int>(screenRightBottom_.y),
            0,
            0,
            1,
            1,
            graphHandle_,
            BLUE
        );
    }

}