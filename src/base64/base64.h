#ifndef BASE64_H_
#define BASE64_H_

#include <cctype>
#include <string>
#include <vector>

namespace denko {

// Use unsigned char to avoid errors in shift operations.
using byte_t = unsigned char;

class Base64 {

private:
  // valid base64 chars
  static const std::string base64_chars;
  // padding char is '='
  static const char padding_char;
  // check is the char a valid base64 char
  static inline bool is_base64_chars(byte_t c) {
    return (isalnum(c) || (c == '+') || (c == '/') || (c == '='));
  }

public:
  // encode ( string -> string )
  static std::string encode(const std::string &origin_data);
  // decode ( string -> string )
  static std::string decode(const std::string &encoded_data);
};

} // namespace denko

#endif // BASE64_H_