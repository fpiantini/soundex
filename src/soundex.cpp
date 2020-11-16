#include <unordered_map>

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
            return encodeDigit(word[1]);
        }
        return "";
    }

    std::string Soundex::encodeDigit(char letter) const
    {
        //  - b, f, p, v             : 1
        //  - c, g, j, k, q, s, x, z : 2
        //  - d, t                   : 3
        //  - l                      : 4
        //  - m, n                   : 5
        //  - r                      : 6
        const std::unordered_map<char, std::string> encodings {
            {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
            {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"},
            {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
            {'d', "3"}, {'t', "3"},
            {'l', "4"},
            {'m', "5"}, {'n', "5"},
            {'r', "6"}
        };
        return encodings.find(letter)->second;
    }

    std::string Soundex::zeroPad(const std::string &word) const
    {
        auto zeroNeeded = maxCodeLength - word.length();
        return word + std::string(zeroNeeded, '0');
    }

} // namespace soundex
