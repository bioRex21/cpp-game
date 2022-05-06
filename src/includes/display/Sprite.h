#ifndef SPRITE_H
#define SPRITE_H

#pragma once

#include <glm/glm.hpp>
#include <shaders/BasicShader.h>
#include <string>
#include "geom/BoundBox.h"
class Sprite
{
public:
    float x = 0.0f;
    float y = 0.0f; // common screen y: top = 0
    float gl_y = 0.0f;// opengl y inverted: downwards = closer to zero

    int width = 0;
    int heigth = 0;
    BoundBox *boundBox;
    int t = 0;
    float scale = 1.0f;
    float rotation = 0.0f;
    int life = 1;

    std::string name;

    unsigned int texture1;
    unsigned int VBO;
    unsigned int VAO; // it will save the GL states config
    unsigned int EBO;

    BasicShader *ourShader;
    Sprite();
    ~Sprite();
    void init(char const *image1, int version);
    void render();
    void destroy();
    void updateGameCoords();
    bool overlaps(Sprite *target);

    void takeHit();

private:
// Camera stuff
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float fov = 45.0f;

    void die();
};

#endif
