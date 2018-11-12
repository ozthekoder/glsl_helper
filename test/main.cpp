#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>
#include <iostream>
#include "tokenizer.hpp"

using namespace glsl;
// Simple test, does not use gmock
TEST(Tokenizer, tokens)
{
    Tokenizer tokenizer;
    EXPECT_EQ(Tokenizer::tokens[0].type, std::string("SPACE"));
    EXPECT_EQ(Tokenizer::tokens[0].pattern, std::string("\s+"));
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

TEST(Tokenizer, tokenize)
{
    Tokenizer tokenizer;
    std::ifstream fileStream(PROJECT_SOURCE_DIR "/shaders/multiple_lights.vert");
    auto src = std::string(std::istreambuf_iterator<char>(fileStream), std::istreambuf_iterator<char>());
    std::vector<Lexeme> lexemes = tokenizer.tokenize(src);
    EXPECT_EQ(1, 1);
}