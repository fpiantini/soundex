#if !defined LIBSOUNDEX_HEADER
#define LIBSOUNDEX_HEADER

#include <string>

namespace soundex
{

  class Soundex
  {
  public:
    std::string encode(const std::string &word) const;

  private:
    std::string head(const std::string &word) const;
    std::string encodeDigits(const std::string &word) const;
    std::string encodeDigit() const;
    std::string zeroPad(const std::string &word) const;
  };

} // namespace soundex

#endif // #if !defined LIBSOUNDEX_HEADER
