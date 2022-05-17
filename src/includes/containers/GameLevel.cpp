//
// Created by abe on 5/11/22.
//

#include <iostream>
#include "GameLevel.h"
#include "geom/Point.h"

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};


GameLevel::GameLevel() {
    timer = new WonkyTimer(500);
    enemyGroup = new SpriteGroup();
}

GameLevel::~GameLevel() {

}

void GameLevel::init(std::vector<Point *> spawnPoints){
    for (std::size_t i = 0; i < spawnPoints.size(); ++i) {
        std::cout<<"point at "<< i <<std::endl;
    }
}

void GameLevel::onSpawnEnemy(){
    enemyGroup->createAndAdd("orange.png", -420, 10);
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
