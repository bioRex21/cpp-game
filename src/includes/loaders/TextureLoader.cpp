#include "TextureLoader.h"
#include <string>
#include <iostream>

namespace loaders
{

  TextureLoader::TextureLoader()
  {
  }

  TextureLoader::~TextureLoader()
  {
  }

  void TextureLoader::loadFromFile(std::string fileName)
  {
    std::cout << "will load" << fileName << std::endl;
  }

}
