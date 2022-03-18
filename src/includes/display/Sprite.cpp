#include "Sprite.h"
#include <iostream>

#include "loaders/TextureLoader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include "vertexUtils/VertexUtils.h"
#include <cmath>



Sprite::Sprite()
{
}

Sprite::~Sprite()
{
  destroy();
  std::cout << "deleted" << std::endl;
}

void Sprite::init(char const *image1, int version = 0)
{

  this->ourShader = new BasicShader("basic_sprite_shader.vert", "basic_sprite_shader.frag");
// TODO: extend image size to use whole sprite area (should be stretched, but looks good)
  ourShader->use();
  std::cout << "Sprite init" << std::endl;
  loaders::TextureLoader *tl = new loaders::TextureLoader();

  VertexUtils *vutils = new VertexUtils();
// probably copy the array pointer into an explicit one (float verts[20])
  float *verts2 = vutils->getOrthoTextureRectangle(0.0, 0.0, 400, 426);
  float vertsa[20]; 
  std::copy(verts2, verts2 + 20, vertsa);

  unsigned int indices2[6];
  //std::copy(VertexUtils::centeredImageVertices, VertexUtils::centeredImageVertices + 20, verts2);
  std::copy(VertexUtils::indices, VertexUtils::indices + 6, indices2);

  glGenTextures(1, &texture1);
  glBindTexture(GL_TEXTURE_2D, texture1);
  tl->loadFromFile(image1);
  this->name = image1;

  glGenBuffers(1, &EBO);
  glGenBuffers(1, &VBO);
  glGenVertexArrays(1, &VAO);

  //* bind the Vertex Array Object first, then bind and set vertex buffer(s),
  //* and then configure vertex attributes(s).
  glBindVertexArray(VAO); // activating to save the following states:


  // position attribute (vertices)
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertsa), vertsa, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);

  // param1: vertex attribute number, param2: size of vert attribute (vec3 = 3), type, normalize,
  // stride how many valies per vertex in our vertices[] array= xyz (3) + colors(3) + tex coords or st (2)
  //  offset in the vertex [x,y,z,r,g,b,s,t]
  //                        ^               offset 0 for position (xyz)
  //                                ^       offset 3 for colors (rgb)
  //                                    ^   offset 6 for texture coordinates (st)
  //  position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  // color attribute
  // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
  // glEnableVertexAttribArray(1);
  // texture coord attribute
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  // note that this is allowed, the call to glVertexAttribPointer registered VBO
  // as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
  glBindBuffer(GL_ARRAY_BUFFER, 0); // turn off saving state, we're done. Now can use it at render loop.

  // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO,
  // but this rarely happens. Modifying other
  // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs)
  // when it's not directly necessary.
  glBindVertexArray(0);
  glActiveTexture(0);
  glBindTexture(GL_TEXTURE_2D, 0);
}

void Sprite::render()
{
  // be sure to activate the shader
  ourShader->use();
  glUniform1i(glGetUniformLocation(ourShader->ID, "texture1"), 0);
  //  or set it via the texture class
  //  ourShader->setInt("texture1", 0);

  glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
  glBindTexture(GL_TEXTURE_2D, texture1);

  glm::mat4 model = glm::mat4(1.0f);
  //center, using image size
  float imageWidth = 387.0f;
  float imageHeight = 419.0f; //  419/2 = 209.5
  float scaledHeight = imageHeight * scale;
    float yOffset = imageHeight - scaledHeight;
    float scaledWidth = imageWidth * scale;
    float xOffset = -scaledWidth / 2.0f;
 //model = glm::translate(model, glm::vec3(-imageWidth / 2.0f , imageHeight / 2.0f , 0.0f));
 //std::cout << this->name << " translate (or just current pos)" << x << "," << y << std::endl;
model = glm::translate(model, glm::vec3(x - (scaledWidth * 0.5) , y + (scaledHeight *0.5f) + yOffset , 0.0f));

  model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    //model = glm::translate(model, glm::vec3(x , y , 0.0f));

    //resize
    model = glm::scale(model, glm::vec3(scale , scale , 1.0f));
    
//model = glm::translate(model, glm::vec3(x , yOffset * (1.0f/scale) , 0.0f));
    //center
    //model = glm::translate(model, glm::vec3(-x , yOffset , 0.0f));
    //scale user input
    //model = glm::translate(model, glm::vec3(x * scale , -y * scale , 0.0f));

    
std::cout << "xy" << x << "," << y << " scale " << scale << " offsetY " << yOffset << std::endl;

  glm::mat4 projection;
  //projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);
  projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f,  0.1f, 100.0f);
  // model = glm::rotate(model, (float)glfwGetTime() * glm::radians(0.012f), glm::vec3(0.5f, 1.0f, 0.0f));
  int modelLoc = glGetUniformLocation(ourShader->ID, "model");
  // glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

  
  glm::mat4 view;
  view = glm::translate(view, glm::vec3(0.0f, 175.0f, -2.0f));
  //view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

  int viewLoc = glGetUniformLocation(ourShader->ID, "view");
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

  int projectionLoc = glGetUniformLocation(ourShader->ID, "projection");
  glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

  // model = glm::rotate(model, (float)glfwGetTime() * glm::radians(15.012f), glm::vec3(1.0f, 0.3f, 0.5f));
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

  // using the sate we saved previously
  glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
                          // glDrawArrays(GL_TRIANGLES, 0, 3);

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void Sprite::destroy()
{
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
}
