#pragma once

class Player;
class Enemy;

class GameScene {
private:

    Player* player_;
    Enemy* enemy_;

public:
    GameScene();
    ~GameScene();
    void Init();
    void Update(char(&keys)[256]);
    void Draw();
};