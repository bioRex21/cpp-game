#include "Sprite.h"
#include <iostream>

#include "loaders/TextureLoader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include <cmath>


unsigned int texture1;
unsigned int VBO;
unsigned int VAO; // it will save the GL states config
unsigned int EBO;
// Camera stuff
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float fov = 45.0f;
int ourShaderID;



Sprite::Sprite()
{
}

Sprite::~Sprite()
{
}

void Sprite::init()
{
  std::cout << "Sprite init" << std::endl;
  loaders::TextureLoader *tl = new loaders::TextureLoader();
  float vertices[] = {
      // positions          // texture coords
      0.5f, 0.5f, 0.0f, 1.0f, 1.0f,   // top right
      0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
      -0.5f, 0.5f, 0.0f, 0.0f, 1.0f   // top left
  };
  // indicate which vertices to use for first and second triangle
  unsigned int indices[] = {
      // note that we start from 0!
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };

  glGenTextures(1, &texture1);
  glBindTexture(GL_TEXTURE_2D, texture1);
  char const *image1 = "squid2.png";
  tl->loadFromFile(image1);

  glGenBuffers(1, &EBO);
  glGenBuffers(1, &VBO);
  glGenVertexArrays(1, &VAO);

  //* bind the Vertex Array Object first, then bind and set vertex buffer(s),
  //* and then configure vertex attributes(s).
  glBindVertexArray(VAO); // activating to save the following states:

  // position attribute (vertices)
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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

    this->ourShader = new BasicShader("basic_sprite_shader.vert", "basic_sprite_shader.frag");
  // be sure to activate the shader
  ourShader->use();
  glUniform1i(glGetUniformLocation(ourShader->ID, "texture1"), 0);
  // or set it via the texture class
  // ourShader.setInt("texture1", 0);
}

void Sprite::render()
{
  glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    // glm::mat4 view = glm::mat4(1.0f);
    //  note that we're translating the scene in the reverse direction of where we want to move
    // view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);

  // model = glm::rotate(model, (float)glfwGetTime() * glm::radians(0.012f), glm::vec3(0.5f, 1.0f, 0.0f));
  int modelLoc = glGetUniformLocation(ourShader->ID, "model");
  // glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

  const float radius = 10.0f;
  float camX = sin(glfwGetTime()) * radius;
  float camZ = cos(glfwGetTime()) * radius;
  glm::mat4 view;
  view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

//std::cout<< "ID is "<< ourShader->ID <<std::endl;
  int viewLoc = glGetUniformLocation(ourShader->ID, "view");
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

  int projectionLoc = glGetUniformLocation(ourShader->ID, "projection");
  glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

  glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
  glBindTexture(GL_TEXTURE_2D, texture1);

  // using the sate we saved previously
  glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
                          // glDrawArrays(GL_TRIANGLES, 0, 3);
  // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  // model = glm::rotate(model, (float)glfwGetTime() * glm::radians(15.012f), glm::vec3(1.0f, 0.3f, 0.5f));
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  // }
  // glBindVertexArray(0); // no need to unbind it every time
}

void Sprite::destroy()
{
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
}
