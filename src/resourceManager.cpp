#include <resourceManager.hpp>

shader& resourceManager::loadShader(const std::string& name, const std::filesystem::path vertexPath, const std::filesystem::path& fragmentPath) {
    auto it = shaders.find(name);
    if (it != shaders.end()) {
        return it->second;
    }

    auto [insertedIt, success] = shaders.emplace(name, shader(vertexPath, fragmentPath));
    
    if (!success) {
        std::cerr << "[ResourceManager] Failed to store shader: " << name << std::endl;
    }

    return insertedIt->second;
}

shader& resourceManager::getShader(const std::string& name) {
    auto it = shaders.find(name);
    if (it == shaders.end()) {
        std::cerr << "[ResourceManager] Shader '" << name << "' not found!" << std::endl;
    }
    return it->second;
}

void resourceManager::clear() {
    shaders.clear();
}