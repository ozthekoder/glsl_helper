#ifndef DEFS_H
#define DEFS_H

#include <regex>
#include <string>

namespace glsl
{

struct Lexeme
{
    std::regex pattern;
};

struct Token
{
    Lexeme lexeme;
    size_t line;
    std::string value;
};

}; // namespace glsl
#endif