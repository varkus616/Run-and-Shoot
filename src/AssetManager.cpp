#include "AssetManager.h"

AssetManager* AssetManager::_instancePtr = nullptr;

AssetManager::AssetManager()
{
    if (_instancePtr == nullptr)
        _instancePtr = this;
}
AssetManager::~AssetManager()
{
    delete _instancePtr;
}
AssetManager* AssetManager::getInstance()
{
    if (_instancePtr == nullptr)
        _instancePtr = new AssetManager();
    return _instancePtr;
}
void AssetManager::loadTexture(const std::string filename,
                               const Textures::ID id)
{
    auto& textures = _instancePtr->_textureMap;
    auto tempPair = std::make_pair(id,filename);
    auto found = textures.find(tempPair);

    if (found != textures.end())
        throw std::runtime_error("ERROR: Couldn't load texture");
    auto& texture = textures[tempPair];
    texture.loadFromFile("Assets/Textures/" + filename);
}

void AssetManager::loadFont(const std::string filename,
                            const Fonts::ID id)
{
    auto& fonts = _instancePtr->_fontMap;
    auto tempPair = std::make_pair(id,filename);
    auto found = fonts.find(tempPair);

    if (found != fonts.end())
        throw std::runtime_error("ERROR: Couldn't load font");
    auto& font = fonts[tempPair];
    font.loadFromFile("Assets/Fonts/" + filename);
}

void AssetManager::clearTextures()
{
    auto& textures = _instancePtr->_textureMap;
    textures.clear();
}

void AssetManager::clearFonts()
{
    auto& fonts = _instancePtr->_fontMap;
    fonts.clear();
}


sf::Texture& AssetManager::getTexture(Textures::ID id)
{
    auto& textures = _instancePtr->_textureMap;

    for (auto it = textures.begin();it != textures.end();it++)
        if (it->first.first == id)
            return it->second;
    throw std::runtime_error("ERROR: Couldn't find desired texture");
}

sf::Font& AssetManager::getFont(Fonts::ID id)
{
    auto& fonts = _instancePtr->_fontMap;

    for (auto it = fonts.begin();it != fonts.end();it++)
        if (it->first.first == id)
            return it->second;
    throw std::runtime_error("ERROR: Couldn't find desired font");
}
