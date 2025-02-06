#include "base64.h"

namespace denko {

const std::string Base64::base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                         "abcdefghijklmnopqrstuvwxyz"
                                         "0123456789+/";
const char Base64::padding_char = '=';

std::string Base64::encode(const std::string &origin_data) {
  std::string encoded;

  int i = 0, j = 0;
  byte_t chars_3[3]; // 每组3个字节
  byte_t chars_4[4]; // 分成4块每块6个比特

  for (const byte_t &byte : origin_data) {
    chars_3[i++] = byte;
    if (i == 3) {

      chars_4[0] = (chars_3[0] & 0xfc) >> 2;
      chars_4[1] = ((chars_3[0] & 0x03) << 4) | ((chars_3[1] & 0xf0) >> 4);
      chars_4[2] = ((chars_3[1] & 0x0f) << 2) | ((chars_3[2] & 0xc0) >> 6);
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
    chars_4[1] = ((chars_3[0] & 0x03) << 4) | ((chars_3[1] & 0xf0) >> 4);
    chars_4[2] = ((chars_3[1] & 0x0f) << 2) | ((chars_3[2] & 0xc0) >> 6);
    chars_4[3] = chars_3[2] & 0x3f;

    for (j = 0; j < i + 1; ++j) {
      encoded.push_back(base64_chars[chars_4[j]]);
    }

    while (i++ < 3) {
      encoded.push_back(padding_char);
    }
  }

  return encoded;
}

std::string Base64::decode(const std::string &encoded_data) {
  std::string decoded;

  int i = 0, j = 0;
  byte_t chars_3[3]; // 每组3个字节
  byte_t chars_4[4]; // 分成4块每块6个比特

  for (const byte_t &byte : encoded_data) {

    if (!is_base64_chars(byte)) {
      return {};
    }

    if (byte == '=') {
      break;
    }

    chars_4[i++] = byte;
    if (i == 4) {

      // 将字符变为对应的编码
      for (i = 0; i < 4; ++i) {
        chars_4[i] = static_cast<byte_t>(base64_chars.find(chars_4[i]));
      }

      // 将编码解出为3个字节一组
      chars_3[0] = ((chars_4[0] & 0x3f) << 2) | ((chars_4[1] & 0x30) >> 4);
      chars_3[1] = ((chars_4[1] & 0x0f) << 4) | ((chars_4[2] & 0x3c) >> 2);
      chars_3[2] = ((chars_4[2] & 0x03) << 6) | (chars_4[3] & 0x3f);

      // 完成一组解码
      for (i = 0; i < 3; ++i) {
        decoded.push_back(chars_3[i]);
      }

      i = 0;
    }
  }

  // 处理尾部
  if (i > 0) {

    // 用 \0 填充剩余
    for (j = i; j < 4; ++j) {
      chars_4[j] = '\0';
    }

    // 将字符变为对应的编码
    for (j = 0; j < 4; ++j) {
      chars_4[j] = static_cast<byte_t>(base64_chars.find(chars_4[j]));
    }

    // 将编码解出为3个字节一组
    chars_3[0] = ((chars_4[0] & 0x3f) << 2) | ((chars_4[1] & 0x30) >> 4);
    chars_3[1] = ((chars_4[1] & 0x0f) << 4) | ((chars_4[2] & 0x3c) >> 2);
    chars_3[2] = ((chars_4[2] & 0x03) << 6) | (chars_4[3] & 0x3f);

    // 完成尾部解码
    for (j = 0; j < i - 1; ++j) {
      decoded.push_back(chars_3[j]);
    }
  }

  return decoded;
}

bool Base64::encode(const std::string &in_file, const std::string &out_file) {
  std::ifstream in(in_file);
  if (!in) {
    std::cerr << "ifstream: open in_file failed." << std::endl;
    return false;
  }

  std::ofstream out(out_file, std::ios::trunc);
  if (!out) {
    std::cerr << "ifstream: open out_file failed." << std::endl;
    in.close();
    return false;
  }

  std::string text;
  in >> text;

  std::string encoded_text = Base64::encode(text);
  if (encoded_text.empty()) {
    std::cerr << "encode: in_file is empty or can not be encoded." << std::endl;
    return false;
  }
  out << encoded_text << std::flush;

  in.close();
  out.close();

  return true;
}

bool Base64::decode(const std::string &in_file, const std::string &out_file) {
  std::ifstream in(in_file);
  if (!in) {
    std::cerr << "ifstream: open in_file failed." << std::endl;
    return false;
  }

  std::ofstream out(out_file, std::ios::trunc);
  if (!out) {
    std::cerr << "ifstream: open out_file failed." << std::endl;
    in.close();
    return false;
  }

  std::string text;
  in >> text;

  std::string decoded_text = Base64::decode(text);
  if (decoded_text.empty()) {
    std::cerr << "decode: in_file is empty or can not be decoded." << std::endl;
    return false;
  }
  out << decoded_text << std::flush;

  in.close();
  out.close();

  return true;
}

} // namespace denko
