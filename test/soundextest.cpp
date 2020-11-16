// Here are the rules for Soundex:
//
// 1. Retain the first letter. Drop all other occurrences of a, e, i, o, u, y, h, w.
// 2. Replace consonants with digits (after the first letter):
//  - b, f, p, v             : 1
//  - c, g, j, k, q, s, x, z : 2
//  - d, t                   : 3
//  - l                      : 4
//  - m, n                   : 5
//  - r                      : 6
// 3. If two adjacent letters encode to the same number, encode them instead
//    as a single number. Also, do so if two letters with the same number are
//    separated by h or w (but code them twice if separated by a vowel). This
//    rule also applies to the first letter.
// 4. Stop when you have a letter and three digits. Zero-pad if needed.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "soundex/soundex.h"

using namespace soundex;
using namespace testing;

class SoundexEncoding : public Test
{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainSoleLetterOfOneLetterWord)
{
    ASSERT_EQ(soundex.encode("A"), "A000");
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
 ASSERT_EQ(soundex.encode("I"), "I000");
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits) {
    EXPECT_EQ(soundex.encode("Ab"), "A100");
    EXPECT_EQ(soundex.encode("Ac"), "A200");
    EXPECT_EQ(soundex.encode("Ad"), "A300");
    EXPECT_EQ(soundex.encode("Ax"), "A200");
}