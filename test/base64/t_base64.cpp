#include "base64.h"
#include <iostream>

int main() {
  using namespace std;
  vector<string> data{"HELLO", "HelloWorld", "A", "你好世界"};
  vector<string> expected{"SEVMTE8=", "SGVsbG9Xb3JsZA==", "QQ==", "5L2g5aW95LiW55WM"};

  size_t length = data.size();
  for (size_t i = 0; i < length; ++i) {
    auto origin = data[i];
    auto correct = expected[i];
    string encoded = denko::Base64::encode(origin);
    string decoded = denko::Base64::decode(encoded);

    cout << "origin: " << origin << '\n';
    cout << "correct: " << correct << '\n';
    cout << "encoded: " << encoded << '\n';
    cout << "decoded: " << decoded << '\n' << endl;
  }

  return 0;
}