#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <MyClass.h>
#include "display/Sprite.h"
#include "display/SpriteGroup.h"
#include "timeUtils/WonkyTimer.h"
#include "containers/GameLevel.h"
#include <vector>
#include <iostream>

void processInput(GLFWwindow *window);
void destroyBlue();
bool isDestroyed = false;
float deltaTime = 0.0f; // Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

//WonkyTimer *wonkyTimer;
//Sprite *orangeSquid;
//Sprite *otherSquid;

GameLevel *currentLevel;

int main()
{

    MyClass *mc = new MyClass();
    mc->init();
    mc->createWindow();
    GLFWwindow *window = mc->myWindow;

    currentLevel = new GameLevel();
    currentLevel->init();
    /*
     *wonkyTimer = new WonkyTimer(500);
    SpriteGroup *spriteGroup = new SpriteGroup();
    //spriteGroup->add("yellow.png", 0.0f, 0.0f);
    //spriteGroup->add("blue.png", 400.0f, 300.0f);
    orangeSquid = new Sprite();
    char const *orangeFile = "orange.png";
    orangeSquid->init(orangeFile, 2);
    orangeSquid->x = 600; //400x426
    orangeSquid->y = 313; //400x426
    orangeSquid->updateGameCoords();
    otherSquid = new Sprite();
    char const *otherFile = "yellow.png";
    otherSquid->init(otherFile, 2);
    otherSquid->x = 0; //400x426
    otherSquid->y = 0; //400x426
    otherSquid->updateGameCoords();
     */

    //glEnable(GL_DEPTH_TEST); <-- disable this for orthographic

    // render loop
    // -----------
    glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // OUR DRAWING
        currentLevel->update();
        //orangeSquid->render();
        //otherSquid->render();
        //bool collides = orangeSquid->overlaps(otherSquid);
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

    //wonkyTimer->addDeltaTime(deltaTime);

    //std::cout<<"delta time:"<<deltaTime<<std::endl;
    /*
        delta time:0.00 706577
        delta time:0.00 665689
        delta time:0.00 713897
     */

    float moveSpeed = 200.0f * deltaTime;
    float scaleSpeed = 1.1f * deltaTime;
    float rotationSpeed = 50.0f * deltaTime;

    currentLevel->processInput(window);

    /*
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)// move up on screen (closer to zero)
    {
        orangeSquid->y -= moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        orangeSquid->y += moveSpeed; // mode down 
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        orangeSquid->x -= moveSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        orangeSquid->x += moveSpeed;

    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        orangeSquid->scale -= scaleSpeed;
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        orangeSquid->scale += scaleSpeed;

    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
        orangeSquid->rotation -= rotationSpeed;
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
        orangeSquid->rotation += rotationSpeed;

    if (orangeSquid->x >= 1.0 && isDestroyed == false)
    {
        isDestroyed = true;
        destroyBlue();
    }
    */

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
