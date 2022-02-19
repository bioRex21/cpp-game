#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#include <glad/glad.h>

#include <string>
namespace loaders {
class TextureLoader {
 public:
  TextureLoader();
  ~TextureLoader();

  void loadFromFile(char const *fileName);

 private:
};
}  // namespace loaders
#endif
