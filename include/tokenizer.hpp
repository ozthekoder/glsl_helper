#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "defs.h"
namespace glsl
{
class Tokenizer
{
public:
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

  Token *findTokenByName(std::string name)
  {
    for (auto t : tokens)
    {
      if (t.name == name)
      {
        return &t;
      }
    }

    return nullptr;
  }

  void preprocessPattern(std::string &pattern)
  {
    std::regex re("<.+>");
    std::smatch match;

    std::string curr = pattern;
    while (std::regex_search(pattern, match, re))
    {
      std::string subpattern = match.str().substr(1, match.str().length() - 2);

      for (auto t : tokens)
      {
        if (t.name == subpattern)
        {
          pattern = std::regex_replace(pattern, std::regex(match.str()), t.pattern);
        }
      }
    }
  }

private:
};
} // namespace glsl
#endif