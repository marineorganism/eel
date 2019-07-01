#ifndef CONSTANT_H
#define CONSTANT_H

/**
 * Namespace that provides values that are constant for the compiled application.
 */
namespace Constant {
    // Versions.
    constexpr static int const VERSION_MAJOR = 0;
    constexpr static int const VERSION_MINOR = 1;
    constexpr static int const VERSION_REVISION = 0;
    // Engine constant values.
    constexpr static float const FPS = 60;
    constexpr static float const FPS_WARN = 55;
    constexpr static int const BULLET_LIMIT = 2048;
    constexpr static int const FILENAME_BUFFER_SIZE = 64;
    constexpr static int const SMALL_TEXT_BUFFER_SIZE = 256;
    constexpr static int const TIMER_LIMIT = 128;
    // Filenames
    constexpr static char const *BULLET_FILE = "bullets";
    constexpr static char const *FISHES_FILE = "fishes";
}

#endif
