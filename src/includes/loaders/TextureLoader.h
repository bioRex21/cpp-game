#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#pragma once

#include <string>
//using namespace std;

namespace loaders
{
    class TextureLoader
    {
    public:
        TextureLoader();
        ~TextureLoader();

        void loadFromFile(std::string fileName);

    private:

    };
}
#endif
