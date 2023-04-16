#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <ResourceIdentifiers.h>
#include <map>
#include <utility>

class AssetManager
{
    public:
        AssetManager();
        ~AssetManager();
        static void loadTexture(const std::string filename,
                                const Textures::ID id);
        static void loadFont(const std::string filename,
                             const Fonts::ID id);

        static void clearTextures();
        static void clearFonts();

        static sf::Texture& getTexture(Textures::ID id);
        static sf::Font&    getFont(Fonts::ID id);

        static AssetManager* getInstance();
    private:
        typedef std::pair<Textures::ID,std::string> idTextFile;
        typedef std::pair<Fonts::ID,std::string> idFontFile;

        std::map<idTextFile,sf::Texture> _textureMap;
        std::map<idFontFile,sf::Font>    _fontMap;

        static AssetManager* _instancePtr;
};

#endif // ASSETMANAGER_H
