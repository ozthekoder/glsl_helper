#include "tokenizer.hpp"

namespace glsl
{
std::vector<Lexeme *> Tokenizer::tokenize(std::string source)
{
    std::vector<std::string> pieces = split(source);
    std::vector<Lexeme *> lexemes;
    for (auto piece : pieces)
    {
        std::string str = piece;
        while (str.length() > 0)
        {
            for (auto token : tokens)
            {
                auto lex = matchString(str, token);
                if (lex != nullptr)
                {
                    lexemes.push_back(lex);
                }
            }
        }
    }

    return lexemes;
}
} // namespace glsl