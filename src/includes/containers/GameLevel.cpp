//
// Created by abe on 5/11/22.
//

#include <iostream>
#include "GameLevel.h"
#include "geom/Point.h"
#include "timeUtils/NumberUtils.h"

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};


GameLevel::GameLevel() {
    timer = new WonkyTimer(500);
    enemyGroup = new SpriteGroup();
    enemyGroup->direction = "left";
}

GameLevel::~GameLevel() {

}

void GameLevel::init(std::vector<Point *> spawnPoints){
    for (std::size_t i = 0; i < spawnPoints.size(); ++i) {
        std::cout<<"point at "<< i <<std::endl;
    }
    this->spawnPoints = spawnPoints;
}

void GameLevel::onSpawnEnemy(){
    Sprite *enemy = new Sprite();
    int max =  (int) spawnPoints.size();
    int random = nu->getRandom(0, max - 1);
    Point *point = spawnPoints[random];
    enemy->init("ball.png");
    enemy->x = point->x;
    enemy->y = point->y;
    enemyGroup->add(enemy);

}

void GameLevel::update(){
    enemyGroup->update();
}

void GameLevel::processInput(GLFWwindow *window) {

    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    timer->addDeltaTime(deltaTime);
    if(timer->trigger) {
        onSpawnEnemy();
        timer->trigger = false;
    }

    float moveSpeed = 200.0f * deltaTime;
    float scaleSpeed = 1.1f * deltaTime;
    float rotationSpeed = 50.0f * deltaTime;

    /*
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        orangeSquid->y -= moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        orangeSquid->y += moveSpeed; // mode down
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        orangeSquid->x -= moveSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        orangeSquid->x += moveSpeed;
        */

}
