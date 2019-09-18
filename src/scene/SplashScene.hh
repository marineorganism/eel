#ifndef SPLASH_SCENE_H
#define SPLASH_SCENE_H

#include "scene/Scene.hh"

/**
 * First scene when game starts, and last when it finishes.
 */
class SplashScene: public Scene {
    public:
        // TODO: make this short in debug mode and long in main mode.
        constexpr static float const WAIT = 1.32;

        /**
         * Does setting up.
         * @param engine is the game services.
         */
        SplashScene(Engine const *engine);

        virtual ~SplashScene();

    private:
        static unsigned char const LOGO[];
        static unsigned int const LOGO_SIZE;
        sf::Texture texture;
        sf::RectangleShape shape;
        float width;
        float height;
        char const *startScript;
        float timer;

        virtual void render(
            sf::RenderTarget *target,
            sf::RenderStates states
        ) const override;

        virtual void logic(float delta) override;
};

#endif
