#pragma once

#include <unordered_map>
#include <string>
#include "shader.hpp"

class resourceManager
{
private:
    resourceManager() = default;
    static std::unordered_map<std::string, shader> shaders;
public:
    static shader& loadShader(const std::string& name, const std::filesystem::path vertexPath, const std::filesystem::path& fragmentPath);
    static shader& getShader(const std::string& name);
    static void clear();
};