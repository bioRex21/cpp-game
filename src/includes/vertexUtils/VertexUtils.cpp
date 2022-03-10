
#include "VertexUtils.h"
#include "vertexUtils/Constants.h"
#include <iostream>

VertexUtils::VertexUtils()
{
}

VertexUtils::~VertexUtils()
{
}
// from -1 to 1
float *VertexUtils::convert(float xPixels, float yPixels)
{
  /*
  w 800       h 600
    400px =0      300px = 0

coords xy:
  400px, 0px 
  0, 1 

  400px, 300px
  0, 0

  0px, 300px
  -1, 0

  0px, 0px
  -1, 1
*/
  float xZeroToOne = xPixels / Constants::WIDTH;
  float xZeroToTwo = xZeroToOne * 2.0;
  float xClipSpace = xZeroToTwo - 1.0;

  

  float yZeroToOne = yPixels / Constants::HEIGHT;
  float yZeroToTwo = yZeroToOne * 2.0;
  float yClipSpace = (yZeroToTwo - 1.0) * -1;

  float *converted = new float[2];// = {xClipSpace, yClipSpace};
  converted[0] = xClipSpace;
converted[1] = yClipSpace;

  std::cout << " converted  x "<< xPixels <<" to = " << xClipSpace << std::endl;
  std::cout << " converted  y "<< yPixels <<" to = " << yClipSpace << std::endl;
  std::cout << "into addres" << converted << std::endl;

  return converted;
}

float *VertexUtils::getTextureRectangleAtPos(float xPixels, float yPixels, float widthPixels, float heightPixels)
{
  /*
   0px = -1
   400px = 0
   800px = 1
  */

/*
Counter-clock-wise vertex order?? clockwise...?

    D ------- A
    |         |
    |         |
    |         |
    C ------- B

  */
 //never eters here?
 std::cout << " " << std::endl;
std::cout << " " << std::endl;
std::cout << "RectText will send " << xPixels + widthPixels << "," << yPixels<< std::endl;
  float *positionA = convert(xPixels + widthPixels, yPixels);
  float *positionB = convert(xPixels + widthPixels, yPixels + heightPixels);
  float *positionC = convert(xPixels, yPixels + heightPixels);
  float *positionD = convert(xPixels, yPixels);

std::cout << "results:" << std::endl;

std::cout << "positionA"<< positionA[0]<< ", " << positionA[1] << std::endl;
std::cout << "positionB"<< positionB[0]<< ", " << positionB[1] << std::endl;
std::cout << "positionC"<< positionC[0]<< ", " << positionC[1] << std::endl;
std::cout << "positionD"<< positionD[0]<< ", " << positionD[1] << std::endl;

std::cout << " " << std::endl;
std::cout << "results address:" << std::endl;

std::cout << "positionA"<< positionA<< std::endl;
std::cout << "positionB"<< positionB<< std::endl;
std::cout << "positionC"<< positionC<< std::endl;
std::cout << "positionD"<< positionD<< std::endl;

  static float verts[20] = {
      // positions          // texture coords
      positionA[0], positionA[1], 0.0f, 1.0f, 1.0f,   // top right
      positionB[0], positionB[1], 0.0f, 1.0f, 0.0f,  // bottom right
      positionC[0], positionC[1], 0.0f, 0.0f, 0.0f, // bottom left
      positionD[0], positionD[1], 0.0f, 0.0f, 1.0f   // top left
  };
delete positionA;
delete positionB;
delete positionC;
delete positionD;
/* for testing
  static float verts2[20] = {
      // positions          // texture coords
      0.0f, 1.0, 0.0f, 1.0f, 1.0f,   // top right
      0.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom right
      -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom left
      -1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
  };
*/
  return verts;
}


float *VertexUtils::getQuadAtPos(float xPixels, float yPixels, float widthPixels, float heightPixels)
{
  /*
   0px = -1
   400px = 0
   800px = 1
  */

/*
Counter-clock-wise vertex order?? clockwise...?

    D ------- A
    |         |
    |         |
    |         |
    C ------- B

  */
 //never eters here?
 std::cout << " " << std::endl;
std::cout << " " << std::endl;
std::cout << "Quad will send " << xPixels + widthPixels << "," << yPixels<< std::endl;
  float *positionA = convert(xPixels + widthPixels, yPixels);
  float *positionB = convert(xPixels + widthPixels, yPixels + heightPixels);
  float *positionC = convert(xPixels, yPixels + heightPixels);
  float *positionD = convert(xPixels, yPixels);

std::cout << "results:" << std::endl;

std::cout << ""<< positionA[0]<< ", " << positionA[1] << std::endl;
std::cout << ""<< positionB[0]<< ", " << positionB[1] << std::endl;
std::cout << ""<< positionC[0]<< ", " << positionC[1] << std::endl;
std::cout << ""<< positionD[0]<< ", " << positionD[1] << std::endl;

std::cout << " " << std::endl;
std::cout << "results address:" << std::endl;

std::cout << "positionA"<< positionA<< std::endl;
std::cout << "positionB"<< positionB<< std::endl;
std::cout << "positionC"<< positionC<< std::endl;
std::cout << "positionD"<< positionD<< std::endl;

  static float verts[12] = {
      // positions         
      positionA[0], positionA[1], z2D,  // top right
      positionB[0], positionB[1], z2D, // bottom right
      positionC[0], positionC[1], z2D,// bottom left
      positionD[0], positionD[1], z2D, // top left
  };
delete positionA;
delete positionB;
delete positionC;
delete positionD;
/* for testing
  static float verts2[20] = {
      // positions          // texture coords
      0.0f, 1.0, 0.0f, 1.0f, 1.0f,   // top right
      0.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom right
      -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom left
      -1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
  };
*/
  return verts;
}



float *VertexUtils::getQuadAtPosOrtho(float xPixels, float yPixels, float widthPixels, float heightPixels)
{
  /*
   0px = -1
   400px = 0
   800px = 1
  */

/*
Counter-clock-wise vertex order?? clockwise...?

    D ------- A
    |         |
    |         |
    |         |
    C ------- B

  */
 //never eters here?
 std::cout << " " << std::endl;
std::cout << " " << std::endl;
std::cout << "Quad will send " << xPixels + widthPixels << "," << yPixels<< std::endl;
  float *positionA = convert(xPixels + widthPixels, yPixels);
  float *positionB = convert(xPixels + widthPixels, yPixels + heightPixels);
  float *positionC = convert(xPixels, yPixels + heightPixels);
  float *positionD = convert(xPixels, yPixels);

std::cout << "results:" << std::endl;

std::cout << ""<< positionA[0]<< ", " << positionA[1] << std::endl;
std::cout << ""<< positionB[0]<< ", " << positionB[1] << std::endl;
std::cout << ""<< positionC[0]<< ", " << positionC[1] << std::endl;
std::cout << ""<< positionD[0]<< ", " << positionD[1] << std::endl;

std::cout << " " << std::endl;
std::cout << "results address:" << std::endl;

std::cout << "positionA"<< positionA<< std::endl;
std::cout << "positionB"<< positionB<< std::endl;
std::cout << "positionC"<< positionC<< std::endl;
std::cout << "positionD"<< positionD<< std::endl;

  static float verts[12] = {
      // positions         
      xPixels + widthPixels, yPixels, z2D,  // top right
      xPixels + widthPixels, yPixels + heightPixels, z2D, // bottom right
      xPixels, yPixels + heightPixels, z2D,// bottom left
      xPixels, yPixels, z2D, // top left
  };
delete positionA;
delete positionB;
delete positionC;
delete positionD;
/* for testing
  static float verts2[20] = {
      // positions          // texture coords
      0.0f, 1.0, 0.0f, 1.0f, 1.0f,   // top right
      0.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom right
      -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom left
      -1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
  };
*/
  return verts;
}
