#include "service/repository/TextRepository.hh"
#include "static/Utils.hh"
#include "static/spdlog/spdlog.h"

TextRepository::TextRepository(char const *root): Repository(root) {
    // does nothing.
}

pugi::xml_node TextRepository::getXml(char const *name, char const *tag) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(this->get(name));
    if (!result) {
        spdlog::error("xml file '{}' is not valid", name);
        return 0;
    }
    pugi::xml_node node = doc.child(tag);
    if (!node) {
        spdlog::error("xml file '{}' lacks top level node '{}'", name, tag);
        return 0;
    }
    return node;
}

char const *TextRepository::create(char const *filename) {
    spdlog::info("creating text: '{}'", filename);
    return Utils::readFile(filename);
}