#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "soundex/soundex.h"

using namespace soundex;

class Soundex
{
public:
    std::string encode(const std::string &word) const { return zeroPad(word); }
private:
    std::string zeroPad(const std::string &word) const { return word + "000"; }

};

TEST(SoundexEncoding, RetainSoleLetterOfOneLetterWord)
{
    Soundex soundex;

    // auto encoded = soundex.encode("A");
    // ASSERT_THAT(encoded, testing::Eq("A"));

    ASSERT_EQ(soundex.encode("A"), "A000");
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
 Soundex soundex;

 ASSERT_EQ(soundex.encode("I"), "I000");
}