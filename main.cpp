#include <Novice.h>
#include"Header/TitleScene.h"
#include"Header/GameScene.h"

const char kWindowTitle[] = "LC1A_25_ヨシダ_トモカ_PG2_評価課題2_STGクラス化";

enum SCENE {
    TITLE,
    GAME
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    int scene = TITLE;

    TitleScene* title = new TitleScene();
    GameScene* game = new GameScene();

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);


        switch (scene) {
        case TITLE:

            title->Update(scene);

            title->Draw();

            break;
        case GAME:

            game->Update(keys);
            game->Draw();

            break;

        }

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    delete title;
    delete game;

    // ライブラリの終了
    Novice::Finalize();
    return 0;


}
