//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include <ArabicRoman.h>

TEST(roman_to_arabic, roman_I_converts_to_arabic_1)
{
    EXPECT_EQ(1,RomanToArabic("I"));
}

TEST(roman_to_arabic, roman_III_converts_to_arabic_3)
{
    EXPECT_EQ(3,RomanToArabic("III"));
}

TEST(roman_to_arabic, roman_IV_converts_to_arabic_4)
{
    EXPECT_EQ(4,RomanToArabic("IV"));
}

TEST(roman_to_arabic, roman_V_converts_to_arabic_5)
{
    EXPECT_EQ(5,RomanToArabic("V"));
}

TEST(roman_to_arabic, roman_VII_converts_to_arabic_7)
{
    EXPECT_EQ(7,RomanToArabic("VII"));
}

TEST(roman_to_arabic, roman_IX_converts_to_arabic_9)
{
    EXPECT_EQ(9,RomanToArabic("IX"));
}

TEST(roman_to_arabic, roman_LXVIII_converts_to_arabic_68)
{
    EXPECT_EQ(68,RomanToArabic("LXVIII"));
}

TEST(roman_to_arabic, roman_DXIII_converts_to_arabic_513)
{
    EXPECT_EQ(513,RomanToArabic("DXIII"));
}

TEST(roman_to_arabic, roman_CMXLIX_converts_to_arabic_949)
{
    EXPECT_EQ(949,RomanToArabic("CMXLIX"));
}

TEST(roman_to_arabic, roman_MMMCDXCIX_converts_to_arabic_3499)
{
    EXPECT_EQ(3499,RomanToArabic("MMMCDXCIX"));
}

TEST(roman_to_arabic, invalid_input_throws_exception)
{
    EXPECT_THROW(RomanToArabic("MMMCDQWERTYXIX"),std::runtime_error);
    EXPECT_THROW(RomanToArabic("mmmcdxcix"),std::runtime_error);
    EXPECT_THROW(RomanToArabic("#@!$%^"),std::runtime_error);
}