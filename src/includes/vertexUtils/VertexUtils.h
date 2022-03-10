#ifndef VERTEXUTILS_H
#define VERTEXUTILS_H

#pragma once

class VertexUtils
{
public:
    VertexUtils();
    ~VertexUtils();


    static constexpr float centeredImageVertices[20] = {
      // positions          // texture coords
      0.5f, 0.5f, 0.0f, 1.0f, 1.0f,   // top right
      0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
      -0.5f, 0.5f, 0.0f, 0.0f, 1.0f   // top left
  };

  static constexpr unsigned int indices[6] = {
      // note that we start from 0!
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };



    float *convert(float xPixels, float yPixels);
    float *getTextureRectangleAtPos(float xPixels, float yPixels, float widthPixels, float heightPixels);
    float *getQuadAtPos(float xPixels, float yPixels, float widthPixels, float heightPixels);
    float *getQuadAtPosOrtho(float xPixels, float yPixels, float widthPixels, float heightPixels);

private:
    float z2D = 0.0f;
};
#endif
