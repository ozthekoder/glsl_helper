#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>
#include <iostream>
#include "tokenizer.hpp"
#include "ast.hpp"

using namespace glsl;
// Simple test, does not use gmock
TEST(Tokenizer, tokens)
{
    EXPECT_EQ(tokens.size(), 209);
    EXPECT_EQ(tokens[0].type, TokenType::LEFT_OP);
    EXPECT_EQ(tokens[0].pattern, std::string("<<"));
    EXPECT_EQ(tokens[208].type, TokenType::NONDIGIT);
    EXPECT_EQ(tokens[208].pattern, std::string("[_a-zA-Z]+"));
}

TEST(Tokenizer, resplit)
{
    Tokenizer tokenizer;
    std::string source = std::string("vec3 foo = vec3(1.0, 0.5, 0.2);");
    std::vector<std::string> pieces = tokenizer.split(source);
    EXPECT_EQ(pieces[0], "vec3");
    EXPECT_EQ(pieces[1], "foo");
    EXPECT_EQ(pieces[2], "=");
    EXPECT_EQ(pieces[3], "vec3(1.0,");
    EXPECT_EQ(pieces[4], "0.5,");
    EXPECT_EQ(pieces[5], "0.2);");
}

TEST(Tokenizer, preprocessPattern)
{
    Tokenizer tokenizer;
    std::string pattern = std::string("<NONDIGIT>(<NONDIGIT>|<DIGIT>)*");
    tokenizer.preprocessPattern(pattern);
    EXPECT_EQ(pattern, std::string("[_a-zA-Z]+([_a-zA-Z]+|[0-9]+)*"));
}

TEST(Tokenizer, matchString)
{
    Tokenizer tokenizer;
    std::string str = std::string("foo");
    Lexeme *lex = tokenizer.matchString(str, tokens[203]);
    EXPECT_EQ(lex->token->type, TokenType::IDENTIFIER);
    EXPECT_EQ(str.length(), 0);
}

TEST(Tokenizer, tokenize)
{
    Tokenizer tokenizer;
    std::ifstream fileStream(PROJECT_SOURCE_DIR "/shaders/multiple_lights.vert");
    auto src = std::string(std::istreambuf_iterator<char>(fileStream), std::istreambuf_iterator<char>());
    std::string source = std::string("vec3 foo = vec3(1.0, 0.5, 0.2);");
    std::vector<Lexeme *> lexemes = tokenizer.tokenize(source);

    EXPECT_EQ(1, 1);
}