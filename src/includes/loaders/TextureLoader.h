#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#include <string>
#include <glad/glad.h>
namespace loaders
{
    class TextureLoader
    {
    public:
        TextureLoader();
        ~TextureLoader();

        void loadFromFile(char const *fileName);

    private:

    };
}
#endif
