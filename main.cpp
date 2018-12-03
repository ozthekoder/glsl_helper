#include <stdlib.h>
#include <glsl.hpp>
#include <fstream>
#include <iostream>
#include "defs.h"
#include "tokenizer.hpp"
#include "ast.hpp"

using namespace glsl;

int main(int argc, char *argv[])
{
    Tokenizer tokenizer;
    std::ifstream fileStream(PROJECT_SOURCE_DIR "/shaders/multiple_lights.vert");
    auto src = std::string(std::istreambuf_iterator<char>(fileStream), std::istreambuf_iterator<char>());
    std::string source = std::string("vec3 foo = vec3(1.0, 0.5, 0.2);");
    std::vector<Lexeme *> lexemes = tokenizer.tokenize(source);
    return EXIT_SUCCESS;
}