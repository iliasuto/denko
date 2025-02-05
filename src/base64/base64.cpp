#include "base64.h"

namespace denko {

const std::string base64::base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                         "abcdefghijklmnopqrstuvwxyz"
                                         "0123456789+/";
const char base64::padding_char = '=';

std::string base64::encode(const std::vector<byte_t> &origin_data) {
  std::string encoded;

  int i = 0, j = 0;
  byte_t chars_3[3]; // 每组3个字节
  byte_t chars_4[4]; // 分成4块每块6个比特

  for (auto &byte : origin_data) {
    chars_3[i++] = byte;
    if (i == 3) {

      chars_4[0] = (chars_3[0] & 0xfc) >> 2;
      chars_4[1] = ((chars_3[0] & 0x03) << 4) + ((chars_3[1] & 0xf0) >> 4);
      chars_4[2] = ((chars_3[1] & 0x0f) << 2) + ((chars_3[2] & 0xc0) >> 6);
      chars_4[3] = chars_3[2] & 0x3f;

      for (i = 0; i < 4; i++) {
        encoded += base64_chars[chars_4[i]];
      }
      i = 0;
    }
  }

  // 剩下的字节
  if (i > 0) {
    for (j = i; j < 3; ++j) {
      chars_3[j] = '\0';
    }

    chars_4[0] = (chars_3[0] & 0xfc) >> 2;
    chars_4[1] = ((chars_3[0] & 0x03) << 4) + ((chars_3[1] & 0xf0) >> 4);
    chars_4[2] = ((chars_3[1] & 0x0f) << 2) + ((chars_3[2] & 0xc0) >> 6);
    chars_4[3] = chars_3[2] & 0x3f;

    for (j = 0; j < i + 1; ++j) {
      encoded += base64_chars[chars_4[i]];
    }

    while (i++ < 3)
      encoded += padding_char;
  }

  return encoded;
}

std::vector<byte_t> base64::decode(const std::string &encoded_data) {}

} // namespace denko
