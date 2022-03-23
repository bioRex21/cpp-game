Dependencies

glfw
https://shnoh171.github.io/gpu%20and%20gpu%20programming/2019/08/26/installing-glfw-on-ubuntu.html
sudo apt-get install libglfw3
sudo apt-get install libglfw3-dev

glad
https://askubuntu.com/questions/1186517/which-package-to-install-to-get-header-file-glad-h
go to https://glad.dav1d.de/
select version 4.5, Core profile (or compatibility if doesn't work), "check Local Files" only
in project:
src/includes paste glad folder

Shaders and images need to be in build folder


On windows:

https://medium.com/@vivekjha92/setup-opengl-with-vs-code-82852c653c43


Make sure to copy shaders and assets to build/ folder, whenever they change


Tips:
Rotate around origin
```model = glm::translate(model, glm::vec3( imageWidth *0.5f , imageHeight *0.5f, 0.0f));
model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
model = glm::translate(model, glm::vec3( -imageWidth *0.5f , -imageHeight *0.5f, 0.0f)); ```
source: https://stackoverflow.com/questions/69424015/glm-rotation-in-ortho-space
