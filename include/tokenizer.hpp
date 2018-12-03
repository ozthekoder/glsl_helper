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
  Tokenizer() {}

  std::vector<Lexeme *> tokenize(std::string source);
  std::vector<std::string> split(const std::string &s, std::string rgx_str = "\\s+")
  {
    std::vector<std::string> elems;

    std::regex rgx(rgx_str);

    std::sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
    std::sregex_token_iterator end;

    while (iter != end)
    {
      std::string elem = *iter;
      elems.push_back(elem);
      ++iter;
    }

    return elems;
  }

  Token *findTokenByName(std::string name)
  {
    Token *tkn = nullptr;
    for (auto t : tokens)
    {
      if (t.name == name)
      {
        tkn = &t;
      }
    }

    return tkn;
  }

  Lexeme *matchString(std::string &piece, Token &token)
  {
    Lexeme *lex = nullptr;
    std::string pattern = token.pattern;
    preprocessPattern(pattern);
    std::regex re("^" + pattern);
    std::smatch match;

    if (std::regex_search(piece, match, re))
    {
      std::cout << "SIZE => " << match.size() << std::endl;
      Token *tkn = &token;
      Lexeme l = {tkn, 0, match.str()};
      lex = &l;
      piece = match.suffix();
    }

    return lex;
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