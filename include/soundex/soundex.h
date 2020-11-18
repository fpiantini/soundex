#if !defined LIBSOUNDEX_HEADER
#define LIBSOUNDEX_HEADER

#include <string>

namespace soundex
{

  class Soundex
  {
  public:
    std::string encode(const std::string &word) const;
    std::string encodedDigit(char letter) const;

  private:
    std::string head(const std::string &word) const;
    std::string encodedDigits(const std::string &word) const;
    void encodeHead(std::string &enc, const std::string &word) const;
    void encodeTail(std::string &enc, const std::string &word) const;
    void encodeLetter(std::string &enc, char letter, bool forced = false) const;
    std::string zeroPad(const std::string &word) const;
    std::string lastDigit(const std::string &word) const;
    std::string upperFront(const std::string &word) const;
    std::string tail(const std::string &word) const;
    char lower(char &c) const;
    bool isComplete(const std::string &word) const;
  };

} // namespace soundex

#endif // #if !defined LIBSOUNDEX_HEADER
