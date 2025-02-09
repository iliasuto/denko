#ifndef BASE64_H_
#define BASE64_H_

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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
  /// @brief Sentinel representing an invalid string and NULL string.
  static const std::string NONE;

  /// @brief encode ( string -> string )
  /// @param origin_data
  /// @return encoded data
  static std::string encode(const std::string &origin_data);

  /// @brief decode ( string -> string )
  /// @param encoded_data
  /// @return decoded data
  static std::string decode(const std::string &encoded_data);

  /// @brief encode (file -> file)
  /// @param in_file
  /// @param out_file
  /// @return if encode successly, return ture. Otherwise false.
  static bool encode(const std::string &in_file, const std::string &out_file);

  /// @brief decode (file -> file)
  /// @param in_file
  /// @param out_file
  /// @return if decode successly, return ture. Otherwise false.
  static bool decode(const std::string &in_file, const std::string &out_file);
};

} // namespace denko

#endif // BASE64_H_