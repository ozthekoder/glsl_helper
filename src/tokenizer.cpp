#include "tokenizer.hpp"

namespace glsl
{
std::vector<Lexeme> Tokenizer::tokenize(std::string source)
{
    std::vector<std::string> pieces = split(source);
    std::vector<Lexeme> lexemes;
    for (auto it = pieces.begin(); it != pieces.end(); ++it)
    {
        std::string piece = *it;
        std::string result;
        // std::cout << piece << std::endl;
        for (auto i = tokens.begin(); i != tokens.end(); ++i)
        {
            try
            {
                Token token = *i;
                std::regex re(token.pattern);
                if (std::regex_match(piece, re))
                {
                    std::string type;
                    if (token.type == TokenType::SPACE)
                    {
                        type = "SPACE";
                    }
                    else if (token.type == TokenType::KEYWORD)
                    {
                        type = "KEYWORD";
                    }
                    else if (token.type == TokenType::IDENTIFIER)
                    {
                        type = "IDENTIFIER";
                    }
                    else if (token.type == TokenType::INTEGER_CONSTANT)
                    {
                        type = "INTEGER_CONSTANT";
                    }
                    else if (token.type == TokenType::FLOATING_CONSTANT)
                    {
                        type = "FLOATING_CONSTANT";
                    }
                    else if (token.type == TokenType::OPERATOR)
                    {
                        type = "OPERATOR";
                    }
                    else if (token.type == TokenType::SEMICOLON)
                    {
                        type = "SEMICOLON";
                    }
                    else if (token.type == TokenType::OPEN_BRACE)
                    {
                        type = "OPEN_BRACE";
                    }
                    else if (token.type == TokenType::CLOSE_BRACE)
                    {
                        type = "CLOSE_BRACE";
                    }
                    else
                    {
                        type = "UNIDENTIFIED";
                    }

                    // std::cout << "-> " << type << " , REGEX: " << token.pattern << std::endl;
                    break;
                }
                preprocessPattern(token.pattern);
            }
            catch (std::regex_error &e)
            {
            }
        }
    }

    return lexemes;
}
} // namespace glsl