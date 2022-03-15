#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <MyClass.h>
#include "loaders/TextureLoader.h"
#include "vertexUtils/VertexUtils.h"
#include "vertexUtils/Constants.h"
#include "display/Sprite.h"
#include "display/ColorQuad.h"
#include "display/ColorTriangle.h"
#include "display/SpriteGroup.h"


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <cmath>
#include <iostream>
#include <vector>

void processInput(GLFWwindow *window);
void destroyBlue();
/// std::vector<Sprite*> sprites;

/*
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

*/
bool isDestroyed = false;
float deltaTime = 0.0f; // Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame
// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.

/*
f

bool firstMouse = true;
float yaw = -90.0f; float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
float fov = 45.0f;

*/

Sprite *orangeSquid;

int main()
{

   // VertexUtils *vu = new VertexUtils();
   // float *convertedCoords = vu->convert(400.0, 400.0);
    //std::cout << "converted" << convertedCoords[0] << "," << convertedCoords[1] << std::endl;

    MyClass *mc = new MyClass();
    mc->init();
    mc->createWindow();
    GLFWwindow *window = mc->myWindow;

    SpriteGroup *spriteGroup = new SpriteGroup();
    spriteGroup->add("yellow.png", 0.0f, 0.0f);
    spriteGroup->add("blue.png", 400.0f, 300.0f);



    orangeSquid = new Sprite();
    char const *orangeFile = "orange.png";
    orangeSquid->init(orangeFile, 2);


    //ColorQuad *colorQuad = new ColorQuad();
    //colorQuad->init();

    //ColorTriangle *colorTriangle = new ColorTriangle();
    //colorTriangle->init();

    //glEnable(GL_DEPTH_TEST); <-- disable this for orthographic

    // disable mouse
    // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // render loop
    // -----------
    glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    while (!glfwWindowShouldClose(window))
    {
        ////std::cout << "frame"<<std::endl << std::endl;
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // OUR DRAWING

        //colorTriangle->render();
        spriteGroup->update();
        orangeSquid->render();
        //colorQuad->render();
        // OUR DRAWING ENDS

        //  glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        //  -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // ------------------------------------------------------------------------
    // optional: de-allocate all resources once they've outlived their purpose:
    // s->destroy();
    // Todo:sprite.destroy()
    // glDeleteProgram(ourShader);
    //  glfw: terminate, clearing all previously allocated GLFW resources.
    //  ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{


    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    float moveSpeed = 200.0f * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        orangeSquid->y -= moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        orangeSquid->y += moveSpeed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        orangeSquid->x -= moveSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        orangeSquid->x += moveSpeed;

    if (orangeSquid->x >= 1.0 && isDestroyed == false)
    {
        isDestroyed = true;
        destroyBlue();
    }

}

void destroyBlue()
{
    // sprites.erase(sprites.begin()+1);
    // std::cout << "destroyed" << std::endl;
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    /*
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);
    */
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    /*
    fov -= (float)yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;

        */
}
