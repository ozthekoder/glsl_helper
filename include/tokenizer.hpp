#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "defs.h"
#include <vector>

namespace glsl
{
static const class Tokenizer
{
public:
  static const std::vector<Lexeme> lexemes;
  Tokenizer() {}

  std::vector<Token> tokenize(std::string source);
};
} // namespace glsl
#endif