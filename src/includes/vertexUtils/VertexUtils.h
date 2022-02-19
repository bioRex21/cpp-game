#ifndef VERTEXUTILS_H
#define VERTEXUTILS_H

#pragma once

class VertexUtils {
 public:
  VertexUtils();
  ~VertexUtils();

  static constexpr float centeredImageVertices[20] = {
      // positions          // texture coords
      0.5f,  0.5f,  0.0f, 1.0f, 1.0f,  // top right
      0.5f,  -0.5f, 0.0f, 1.0f, 0.0f,  // bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,  // bottom left
      -0.5f, 0.5f,  0.0f, 0.0f, 1.0f   // top left
  };

  static constexpr unsigned int indices[6] = {
      // note that we start from 0!
      0, 1, 3,  // first triangle
      1, 2, 3   // second triangle
  };

  void convert(float pixelsWidth, float pixelsHeight);

 private:
};
#endif
