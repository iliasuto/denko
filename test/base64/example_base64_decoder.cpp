#include "base64.h"

int main(int argc, char *argv[]) {
  using namespace std;
  using namespace denko;

  if (argc == 1) {

    cout << "输入Base64编码, 输出文本.\n" << "> ";

    string text;
    while (getline(cin, text)) {
      string encoded_text = Base64::decode(text);
      cout << encoded_text << "\n> ";
    }

  } else if (argc == 2) {

    string decoded_file = Base64::decode_file(argv[1]);
    cout << decoded_file << endl;

  } else {

    cerr << "argc: args count too many!" << endl;
    return -1;
  }

  return 0;
}