#include"../Header/GameScene.h"
#include"../Header/Player.h"
#include"../Header/Enemy.h"
#include"../Header/Length.h"

GameScene::GameScene() {

    player_ = new Player;
    enemy_ = new Enemy;

    Init();

}


GameScene::~GameScene() {

    delete player_;
    delete enemy_;

}

void GameScene::Init() {


}

void GameScene::Update(char(&keys)[256]) {

    //更新処理
    player_->Update(keys, enemy_);
    enemy_->Update();

    //自機と敵の当たり判定
    if (!player_->GetIsHit()) {

        if (Length(
            { player_->GetPosX() - enemy_->GetPosX(),player_->GetPosY() - enemy_->GetPosY() }) <= player_->GetRadius() + enemy_->GetRadius()) {
            player_->SetIsHit(true);

        }

    }


}

void GameScene::Draw() {

    //描画処理
    player_->Draw();
    enemy_->Draw();

}

