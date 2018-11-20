#ifndef AST_H
#define AST_H

#include "defs.h"

namespace glsl
{
class ASTNode
{
public:
  TokenType type;
  std::vector<std::string> patterns;
  std::string text;
  std::vector<ASTNode *> children;

  void parse(std::string source);
};
}; // namespace glsl

#endif