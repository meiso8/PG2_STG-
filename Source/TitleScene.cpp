#include"../Header/TitleScene.h"
#include<Novice.h>

void TitleScene::Update(int& scene) {

    if (sceneTimer_ < 120) {
        sceneTimer_++;
    } else {
        scene = 1;
    }
}

void TitleScene::Draw() {

    Novice::ScreenPrintf(0, 0, "TIMER %d",sceneTimer_);
    Novice::ScreenPrintf(640, 360, "TITLE");
    //Novice::ScreenPrintf(640, 360 + 16, "PRESS SPACE");
}
