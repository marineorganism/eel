#include "service/repository/WalkStageRepository.hh"
#include "static/spdlog/spdlog.h"
#include <SFML/Graphics.hpp>

WalkStageRepository::WalkStageRepository(
    char const &root,
    Repository<char> const &textRepo,
    Repository<Tileset> const &tilesetRepo
):
    Repository(root),
    textRepo(textRepo),
    tilesetRepo(tilesetRepo)
{
    // yeeeet.
}

WalkStage *WalkStageRepository::create(
    char const &filename,
    char const &key
) const {
    spdlog::info("creating walkstage: '{}'", &filename);
    pugi::xml_document doc;
    pugi::xml_node node = Utils::openXml(
        doc,
        *"map",
        this->textRepo.get(key).get()
    );

    return walkStage;
}
