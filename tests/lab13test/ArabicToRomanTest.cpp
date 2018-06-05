//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include <ArabicRoman.h>

TEST(arabic_to_roman, arabic_1_converts_to_roman_I)
{
    EXPECT_EQ("I",ArabicToRoman(1));
}

TEST(arabic_to_roman, arabic_3_converts_to_roman_III)
{
    EXPECT_EQ("III",ArabicToRoman(3));
}

TEST(arabic_to_roman, arabic_4_converts_to_roman_IV)
{
    EXPECT_EQ("IV",ArabicToRoman(4));
}

TEST(arabic_to_roman, arabic_5_converts_to_roman_V)
{
    EXPECT_EQ("V",ArabicToRoman(5));
}

TEST(arabic_to_roman, arabic_7_converts_to_roman_VII)
{
    EXPECT_EQ("VII",ArabicToRoman(7));
}

TEST(arabic_to_roman, arabic_9_converts_to_roman_IX)
{
    EXPECT_EQ("IX",ArabicToRoman(9));
}

TEST(arabic_to_roman, arabic_68_converts_to_roman_LXVIII)
{
    EXPECT_EQ("LXVIII",ArabicToRoman(68));
}

TEST(arabic_to_roman, arabic_513_converts_to_roman_DXIII)
{
    EXPECT_EQ("DXIII",ArabicToRoman(513));
}

TEST(arabic_to_roman, arabic_999_converts_to_roman_CMXLIX)
{
    EXPECT_EQ("CMXLIX",ArabicToRoman(999));
}

TEST(arabic_to_roman, arabic_3999_converts_to_roman_MMMCMXLIX)
{
    EXPECT_EQ("MMMCMXLIX",ArabicToRoman(3999));
}

TEST(arabic_to_roman, arabic_0_throws_exception)
{
    EXPECT_THROW(ArabicToRoman(0),std::runtime_error);
}

TEST(arabic_to_roman, arabic_greater_than_3999_throws_exception)
{
    EXPECT_THROW(ArabicToRoman(4657),std::runtime_error);
}

TEST(arabic_to_roman, arabic_negative_throws_exception)
{
    EXPECT_THROW(ArabicToRoman(-37),std::runtime_error);
}