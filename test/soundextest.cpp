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


// -------------------------------------------------------------------------------
// Test area begins here...
// -------------------------------------------------------------------------------
class SoundexEncoding : public testing::Test
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