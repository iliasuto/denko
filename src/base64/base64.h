#ifndef BASE64_H_
#define BASE64_H_

#include <string>
#include <vector>

namespace denko {

class Base64 {

private:
  // valid base64 chars
  static const std::string base64_chars;
  // padding char is '='
  static const char padding_char;
  // check is the char a valid base64 char
  static inline bool is_base64_chars(char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
  }

public:
  // encode
  static std::string encode(const std::string &origin_data);
  // decode
  static std::string decode(const std::string &encoded_data);
};

} // namespace denko

#endif // BASE64_H_