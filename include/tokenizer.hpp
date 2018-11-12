#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "defs.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

namespace glsl
{
class Tokenizer
{
public:
  static const std::vector<Token> tokens;
  std::vector<Lexeme> lexemes;
  Tokenizer() {}

  std::vector<Lexeme> tokenize(std::string source);
  std::vector<std::string> split(const std::string &s, std::string rgx_str = "\\s+")
  {

    std::vector<std::string> elems;

    std::regex rgx(rgx_str);

    std::sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
    std::sregex_token_iterator end;

    while (iter != end)
    {
      elems.push_back(*iter);
      ++iter;
    }

    return elems;
  }

private:
};
} // namespace glsl
#endif