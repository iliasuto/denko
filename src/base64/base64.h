#ifndef BASE64_H_
#define BASE64_H_

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

namespace denko {

/// @brief Use unsigned char to avoid errors in shift operations.
using byte_t = unsigned char;

class Base64 {

private:
  ///@brief valid base64 chars
  static const std::string base64_chars;

  /// @brief padding char
  static const char padding_char;

  /// @brief check is the char a valid base64 char
  static inline bool is_base64_chars(byte_t c) {
    return (isalnum(c) || (c == '+') || (c == '/') || (c == '='));
  }

public:
  /// @brief Sentinel representing on invalid string.
  static const std::string NONE;

  /// @brief encode ( string -> string )
  /// @param origin_data the string to encode to.
  /// @return return encoded string.
  static std::string encode(const std::string &origin_data);

  /// @brief decode ( string -> string )
  /// @param encoded_data the string to decode to.
  /// @return return decoded string. if failed Base64::NONE.
  static std::string decode(const std::string &encoded_data);

  /// @brief encode (file -> string)
  /// @param in_file the filename to encode to.
  /// @return return encoded string.
  static std::string encode_file(const std::string &in_file);

  /// @brief decode (file -> string)
  /// @param in_file the filename to decode to.
  /// @return return decoded string. if failed Base64::NONE.
  static std::string decode_file(const std::string &in_file);
};

} // namespace denko

#endif // BASE64_H_