#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#include <string>
#include <glad/glad.h>
#include "geom/Point.h"

namespace loaders
{
    class TextureLoader
    {
    public:
        TextureLoader();
        ~TextureLoader();

        Point* loadFromFile(char const *fileName);

    private:

    };
}
#endif
