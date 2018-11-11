#ifndef DEFS_H
#define DEFS_H

#include <regex>
#include <string>

namespace glsl
{

struct Token
{
    std::string type;
    std::string pattern;
};

struct Lexeme
{
    Token token;
    size_t line;
    std::string value;
};

}; // namespace glsl
#endif