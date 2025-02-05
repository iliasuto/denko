#ifndef BASE64_H_
#define BASE64_H_

#include <string>
#include <vector>

namespace denko {

using byte_t = unsigned char;

class base64 {

private:
  // valid base64 chars
  static const std::string base64_chars;
  // padding char is '='
  static const char padding_char;
  // check is the char a valid base64 char
  static inline bool is_base64_chars(byte_t c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
  }

public:
  // encode from 8bits' array
  static std::string encode(const std::vector<byte_t> &origin_data);
  // decode to 8bits' array
  static std::vector<byte_t> decode(const std::string &encoded_data);
};

} // namespace denko

#endif // BASE64_H_