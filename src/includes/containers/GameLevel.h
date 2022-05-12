//
// Created by abe on 5/11/22.
//

#ifndef MY_CCP_GAME_GAMELEVEL_H
#define MY_CCP_GAME_GAMELEVEL_H


#include "GLFW/glfw3.h"
#include "timeUtils/WonkyTimer.h"
#include "display/SpriteGroup.h"

class GameLevel {
public:
    GameLevel();

    virtual ~GameLevel();

    void init();

    void update();
    void processInput(GLFWwindow *window);
private:
    WonkyTimer *timer;
    SpriteGroup *enemyGroup;
    float deltaTime = 0.0f; // Time between current frame and last frame
    float lastFrame = 0.0f; // Time of last frame
    void onSpawnEnemy();
};


#endif //MY_CCP_GAME_GAMELEVEL_H
