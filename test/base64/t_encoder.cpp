#include "base64.h"
#include <iostream>
#include <memory.h>

int main(int argc, char *argv[]) {
  using namespace std;
  using namespace denko;

  if (argc == 1) {
    cout << "输入文本, 输出Base64编码.\n" << "> ";

    string text;
    while (getline(cin, text)) {
      string encoded_text = Base64::encode(text);
      cout << encoded_text << "\n> ";
    }
  } else if (argc == 2) {
    std::ifstream in(argv[1]);
    if (!in) {
      std::cerr << "ifstream: open \"" << argv[1] << "\" failed." << std::endl;
      return false;
    }

    std::string text;
    std::string buf;
    // char buf;
    // while (in.read(&buf, 1)) {
    //   text.push_back(buf);
    // }

    while (getline(in, buf)) {
      text += buf;
      text += "\n";
    }

    std::string encoded_text = Base64::encode(text);
    if (encoded_text.empty()) {
      std::cerr << "encode: in_file is empty or can not be encoded."
                << std::endl;
      return false;
    }
    cout << encoded_text << std::flush;

    in.close();
    return true;
  }

  return 0;
}