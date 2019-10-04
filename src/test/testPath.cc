#include "test/catch.hh"
#include "model/Path.hh"

TEST_CASE("path token", "[path]") {
    char const *test = "~/Documents/github/eel/README.md";
    REQUIRE(Path::token(test) == 1);
    REQUIRE(Path::token(test + 1) == 10);
    REQUIRE(Path::token(test + 11) == 7);
    REQUIRE(Path::token(test + 18) == 4);
    REQUIRE(Path::token(test + 22) == 10);
}

TEST_CASE("making nice paths", "[path]") {
    Path path;
    path.apply("camel/pictures");
    path.apply("../sounds");
    char const *expected = "camel/sounds";
    char const *result = path.render();
    for (int i = 0; i < strlen(expected) + 1; i++) {
        REQUIRE(expected[i] == result[i]);
    }
    // also test copy constructor.
    Path babby(&path);
    result = babby.render();
    for (int i = 0; i < strlen(expected) + 1; i++) {
        REQUIRE(expected[i] == result[i]);
    }
    // now remove some
    path.remove("../sounds");
    result = path.render();
    expected = "camel/pictures";
    for (int i = 0; i < strlen(expected) + 1; i++) {
        REQUIRE(expected[i] == result[i]);
    }
}

TEST_CASE("path that starts with ..", "[path]") {
    Path path;
    path.apply("../bongo.tga");
    path.apply("../bongo.tga");
    char const *expected = "../bongo.tga";
    char const *result = path.render();
    for (int i = 0; i < strlen(expected) + 1; i++) {
        REQUIRE(expected[i] == result[i]);
    }
    // test going back past the beginning.
    path.apply("../..");
    expected = "..";
    result = path.render();
    for (int i = 0; i < strlen(expected) + 1; i++) {
        REQUIRE(expected[i] == result[i]);
    }
}

TEST_CASE("make path that is too big", "[path]") {
    Path path;
    for (int i = 0; i < 260; i++) {
        path.apply("/234");
    }
}
