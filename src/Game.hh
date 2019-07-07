#ifndef GAME_H
#define GAME_H

#include "BulletManager.hh"
#include "Listener.hh"
#include "Timer.hh"
#include "Scene.hh"
#include <forward_list>

/**
 * Contains the main loop of the game, handles events, and creates and manages the game's scenes.
 */
class Game {
    Config const *config;
    Repository *repository;
    Builder const *builder;
    Timer *timer;
    BulletManager *bulletManager;
    std::forward_list<Scene *> scenes;
    sf::RenderWindow window;
    sf::View view;

    /**
     * Gets the game to handle events.
     */
    void handleEvents();

    /**
     * Updates the game's state.
     */
    void update();

    /**
     * Renders the game.
     */
    void render();

    /**
     * Does the frame by frame transition of scenes (or does nothing most of the time).
     * @param transitionBuffer is the string defining how the current scene stack should be updated.
     */
    void transition(char const *transitionBuffer);

public:
    /**
     * Builds the thing and gets it's dependencies injected.
     * @param config        is the game's configuration.
     * @param repository    is where the game will get it's assets.
     * @param builder       is the gui builder.
     * @param timer         is used to time stuff.
     * @param bulletManager is used by some scenes for their enjoyment.
     */
    Game(
        Config const *config,
        Repository *repository,
        Builder const *builder,
        Timer *timer,
        BulletManager *bulletManager
    );

    /**
     * Runs the game.
     * @return 0 if it's all been good, and another value if there was an unhandled exception in the game logic.
     */
    int run();
};

#endif
