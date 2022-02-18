#ifndef BASICSHADER_H
#define BASICSHADER_H

#pragma once

#include <string>

class BasicShader
{
public:
    unsigned int ID;
    BasicShader(const char* vertexPath, const char* fragmentPath);
    ~BasicShader();
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
private:
void checkCompileErrors(unsigned int shader, std::string type);

};

#endif
