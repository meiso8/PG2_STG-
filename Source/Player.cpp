#include "../Header/Player.h"
#include"../Header/Transform.h"
#include"../Header/Enemy.h"
#include"../Header/Camera.h"

#include"../Header/AffineMatrix.h"
#include"../Header/DiagonalMatrix.h"
#include"../Header/Length.h"

#ifdef _DEBUG
#include<imgui.h>
#endif // _DEBUG


#include<Novice.h>

//弾の発射
//キー入力による移動


Player::Player() {

    graphHandle_ = Novice::LoadTexture("./NoviceResources/white1x1.png");

    Init();

};



Player::~Player() {

    Novice::UnloadTexture(graphHandle_);

};


void Player::Init() {

    size_ = { 64.0f,64.0f };

    leftTop_ = { -size_.x / 2.0f,-size_.y / 2.0f };
    rightTop_ = { size_.x / 2.0f,-size_.y / 2.0f };
    leftBottom_ = { -size_.x / 2.0f,size_.y / 2.0f };
    rightBottom_ = { size_.x / 2.0f,size_.y / 2.0f };

    theta_ = 0.0f;
    scale_ = { 1.0f,1.0f };
    velocity_ = { 16.0f,16.f };
    worldPos_ = { 64.0f,360.0f };

    worldMatrix_ = DiagonalMatrix1();

    TransformScreen();

    direction_ = { 0.0f,0.0f };
    length_ = 0.0f;

    for (int i = 0; i < BULLET_MAX; ++i) {
        bullet_[i].Init();
    }

    isHit_ = false;
    respawnTimer_ = 30;
};

void Player::TransformScreen() {

    screenLeftTop_ = Transform(leftTop_, worldMatrix_);
    screenRightTop_ = Transform(rightTop_, worldMatrix_);
    screenLeftBottom_ = Transform(leftBottom_, worldMatrix_);
    screenRightBottom_ = Transform(rightBottom_, worldMatrix_);

}

void Player::Move(char(&keys)[256]) {

    //方向初期化
    direction_ = { 0.0f };

    //キー入力移動
    if (keys[DIK_W]) {

        direction_.y = -1.0f;
    }

    if (keys[DIK_A]) {

        direction_.x = -1.0f;
    }

    if (keys[DIK_S]) {

        direction_.y = 1.0f;
    }

    if (keys[DIK_D]) {

        direction_.x = 1.0f;

    }

    //長さ計算
    length_ = Length(direction_);

    //正規化
    if (length_ != 0.0f) {

        direction_.x /= length_;
        direction_.y /= length_;
    }

    //ワールド座標に代入
    worldPos_.x += velocity_.x * direction_.x;
    worldPos_.y += velocity_.y * direction_.y;

}

void Player::Shot(char(&keys)[256]) {

    if (keys[DIK_SPACE]) {

        if (bullet_[0].coolTime_ < 10) {
            bullet_[0].coolTime_++;
        }

        if (bullet_[0].coolTime_ == 10) {

            for (int i = 0; i < BULLET_MAX; ++i) {

                if (!bullet_[i].isShot_) {

                    bullet_[i].worldPos_ = worldPos_;
                    bullet_[i].isShot_ = true;
                    bullet_[0].coolTime_ = 0;
                    break;
                }

            }

        }
    }



}

void Player::Update(char(&keys)[256], Enemy* enemy) {

    Move(keys);

    Shot(keys);

    for (int i = 0; i < BULLET_MAX; ++i) {
        bullet_[i].Update(enemy);
    }

    if (isHit_) {

        if (respawnTimer_ > 0) {
            respawnTimer_--;
        } else {

            Init();
        }

    }

    worldMatrix_ = MakeAffineMatrix(scale_, theta_, worldPos_);

    screenLeftTop_ = Transform(leftTop_, worldMatrix_);
    screenRightTop_ = Transform(rightTop_, worldMatrix_);
    screenLeftBottom_ = Transform(leftBottom_, worldMatrix_);
    screenRightBottom_ = Transform(rightBottom_, worldMatrix_);

#ifdef _DEBUG

    ImGui::Begin("Player");
    ImGui::SliderFloat2("pos", &worldPos_.x, 0.0f, 1280.0f);
    ImGui::SliderFloat2("direction", &direction_.x, -1.0f, 1.0f);

    ImGui::Text("bullet %d", bullet_[0].coolTime_);
    ImGui::Text("isHit %d", isHit_);

    for (int i = 0; i < BULLET_MAX; ++i) {
        ImGui::Text("%d : isShot %d", i, bullet_[i].isShot_);
    }

    ImGui::End();

#endif // _DEBUG


};

void Player::Draw() const {

    for (int i = 0; i < BULLET_MAX; ++i) {
        bullet_[i].Draw();
    }

    if (!isHit_) {

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
            WHITE
        );

    }

    Novice::ScreenPrintf(0, 0, "GAME");

};