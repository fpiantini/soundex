#if !defined LIBSOUNDEX_HEADER
#define LIBSOUNDEX_HEADER

#include <string>

namespace soundex
{

  class Soundex
  {
  public:
    std::string encode(const std::string &word) const { return zeroPad(word); }

  private:
    std::string zeroPad(const std::string &word) const { return word + "000"; }
  };

} // namespace soundex

#endif // #if !defined LIBSOUNDEX_HEADER
