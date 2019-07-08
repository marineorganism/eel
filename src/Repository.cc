#include "Repository.hh"
#include "Config.hh"
#include "Constant.hh"
#include "Utils.hh"
#include "spdlog/spdlog.h"

Repository::Repository(Config const *config) {
    this->config = config;
    char fontFile[Constant::FILENAME_BUFFER_SIZE];
    config->inRoot(fontFile, config->get("font"));
    if (!this->font.loadFromFile(fontFile)) {
        spdlog::critical("Could not load font from file '{}'", fontFile);
        throw -1;
    }
}

sf::Texture *Repository::getTexture(char const *name) {
    spdlog::debug("get texture: '{}'", name);

}

SpriteBatch *Repository::getSpriteBatch(char const *name) {
    spdlog::debug("get sprite batch: '{}'", name);
    try {
        return this->spriteBatches.at(name);
    } catch (...) {
        char filename[Constant::FILENAME_BUFFER_SIZE];
        this->config->inRoot(filename, name);
        SpriteBatch *spriteBatch = new SpriteBatch(filename);
        this->spriteBatches[name] = spriteBatch;
        return spriteBatch;
    }
}

char const *Repository::getText(char const *name) {
    spdlog::debug("get text: '{}'", name);
    try {
        return this->texts.at(name);
    } catch (...) {
        char filename[Constant::FILENAME_BUFFER_SIZE];
        this->config->inRoot(filename, name);
        char *text = Utils::readFile(filename);
        this->texts[name] = text;
        return text;
    }
}

sf::Font const *Repository::getFont() {
    spdlog::debug("get font");
    return &this->font;
}
