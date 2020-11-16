#include "soundex/soundex.h"

static const size_t maxCodeLength = 4;

namespace soundex
{
    // --- Public methods --------------------------------------------
    std::string Soundex::encode(const std::string &word) const
    {
        return zeroPad(head(word) + encodeDigits(word));
    }

    // --- Private methods -------------------------------------------
    std::string Soundex::head(const std::string &word) const
    {
        return word.substr(0, 1);
    }

    std::string Soundex::encodeDigits(const std::string &word) const
    {
        if (word.length() > 1) {
            return encodeDigit();
        }
        return "";
    }

    std::string Soundex::encodeDigit() const
    {
        return "1";
    }

    std::string Soundex::zeroPad(const std::string &word) const
    {
        auto zeroNeeded = maxCodeLength - word.length();
        return word + std::string(zeroNeeded, '0');
    }

} // namespace soundex
