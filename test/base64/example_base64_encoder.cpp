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
    ifstream in(argv[1]);
    if (!in) {
      cerr << "ifstream: open \"" << argv[1] << "\" failed." << endl;
      return -1;
    }

    string text;
    string buf;
    while (getline(in, buf)) {
      text += buf;
      text += "\n";
    }
    in.close();

    string encoded_text = Base64::encode(text);
    if (encoded_text.empty()) {
      cerr << "encode: in_file is empty or can not be encoded." << endl;
      return false;
    }

    cout << encoded_text << flush;

  } else {
    cerr << "argc: args count too many!" << endl;
    return -1;
  }

  return 0;
}