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
                std::string pattern = token.pattern;
                preprocessPattern(pattern);
                std::regex re("^" + pattern);
                std::smatch match;

                std::string curr = piece;
                while (std::regex_search(pattern, match, re))
                {
                    Lexeme lex = {token, 0, match.str()};
                    lexemes.push_back(lex);
                    curr = match.suffix();
                }
            }
            catch (std::regex_error &e)
            {
            }
        }
    }

    return lexemes;
}
} // namespace glsl