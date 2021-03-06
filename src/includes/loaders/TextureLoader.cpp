#include "TextureLoader.h"

#include <iostream>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
namespace loaders {

TextureLoader::TextureLoader() {}

TextureLoader::~TextureLoader() {}

// TODO: Handle jpg/png
void TextureLoader::loadFromFile(char const *fileName) {
  // set the texture wrapping/filtering options (on the currently bound texture
  // object)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // load and generate the texture

  std::cout << "will load " << fileName << std::endl;
  int width, height, nrChannels;
  stbi_set_flip_vertically_on_load(
      true);  // tell stb_image.h to flip loaded texture's on the y-axis.
  unsigned char *data = stbi_load(fileName, &width, &height, &nrChannels, 0);
  if (data) {
    // jpg: glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
    // GL_UNSIGNED_BYTE, data);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, data);  // png
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Failed to load texture" << std::endl;
  }
  stbi_image_free(data);
}

}  // namespace loaders
