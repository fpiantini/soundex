#include <iostream>
#include <unordered_map>

#include "soundex/soundex.h"

static const size_t maxCodeLength = 4;
static std::string NotADigit = "*";
namespace soundex
{
    // --- Public methods --------------------------------------------
    std::string Soundex::encode(const std::string &word) const
    {
        if (word.length() > 0) {
            return zeroPad(upperFront(head(word)) + tail(encodedDigits(word)));
        }
        return "";
    }

    std::string Soundex::encodedDigit(char letter) const
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
        auto it = encodings.find(lower(letter));
        return it == encodings.end() ? NotADigit : it->second;
    }

    // --- Private methods -------------------------------------------
    std::string Soundex::head(const std::string &word) const
    {
        return word.substr(0, 1);
    }

    std::string Soundex::encodedDigits(const std::string &word) const
    {
        std::string enc = "";
        encodeHead(enc, word);
        encodeTail(enc, word);
        return enc;
    }

    void Soundex::encodeHead(std::string &enc, const std::string &word) const
    {
        encodeLetter(enc, word.front(), true);
        //enc += encodedDigit(word.front());
    }

    void Soundex::encodeTail(std::string &enc, const std::string &word) const
    {
        for(auto letter: word) {
            if (isComplete(enc)) break;
            encodeLetter(enc, letter);
        }
    }

    void Soundex::encodeLetter(std::string &enc, char letter, bool forced) const
    {
        auto digit = encodedDigit(letter);
        if (forced || (digit != NotADigit && digit != lastDigit(enc)))
            enc += digit;
    }

    std::string Soundex::zeroPad(const std::string &word) const
    {
        auto zeroNeeded = maxCodeLength - word.length();
        return word + std::string(zeroNeeded, '0');
    }

    std::string Soundex::lastDigit(const std::string &word) const
    {
        if (word.empty()) return NotADigit;
        return std::string(1, word.back());
    }

    std::string Soundex::tail(const std::string &word) const {
        if (word.empty()) return "";
        return word.substr(1);
    }

    std::string Soundex::upperFront(const std::string &word) const
    {
        return std::string(1, std::toupper(static_cast<unsigned char>(word.front())));
    }

    char Soundex::lower(char &c) const
    {
        return std::tolower(static_cast<unsigned char>(c));
    }

    bool Soundex::isComplete(const std::string &word) const
    {
        return word.length() >= maxCodeLength;
    }

} // namespace soundex
