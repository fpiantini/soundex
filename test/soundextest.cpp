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
