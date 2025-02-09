#include "base64.h"

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

    string encoded_file = Base64::encode_file(argv[1]);
    cout << encoded_file << endl;

  } else {

    cerr << "argc: args count too many!" << endl;
    return -1;
  }

  return 0;
}