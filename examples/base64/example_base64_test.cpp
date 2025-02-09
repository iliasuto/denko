#include "base64.h"
#include <vector>
#include <iostream>

int main() {
  using namespace std;
  vector<string> data{
    "HELLO", 
    "HelloWorld", 
    "A", 
    "你好世界",
    "棕色狐狸散りぬる რაფրաλώσσжеγαThe123우가😀"
  };
  vector<string> expected{
    "SEVMTE8=", 
    "SGVsbG9Xb3JsZA==", 
    "QQ==", 
    "5L2g5aW95LiW55WM",
    "5qOV6Imy54uQ54u45pWj44KK44Gs44KLIOGDoOGDkOGDpNaA1aHOu8+Oz4PPg9C20LXOs86xVGhlMTIz7Jqw6rCA8J+YgA=="
  };

  size_t length = data.size();
  for (size_t i = 0; i < length; ++i) {
    string origin = data[i];
    string expect = expected[i];
    string encoded = denko::Base64::encode(origin);
    string decoded = denko::Base64::decode(encoded);

    cout << "origin : " << origin << '\n';
    cout << "expect : " << expect << '\n';
    cout << "encoded: " << encoded << '\n';
    cout << "decoded: " << decoded << '\n' << endl;
  }

  cout << endl << "To test the invalid base64:" << endl;

  string invalid("12313*");
  cout << "invalid == " << invalid << endl;

  string decoded_invalid = denko::Base64::decode(invalid);
  if (decoded_invalid == denko::Base64::NONE)
    cout << "decoded_invalid == denko::Base64::NONE" << endl;

  cout << endl << "NOTICE:\nto decode \"\" returns \"\"." << endl;
  if("" != denko::Base64::NONE) cout << "(\"\" != denko::Base64::NONE)" << endl;
  if("\0" != denko::Base64::NONE) cout << "(\"\\0\" != denko::Base64::NONE)" << endl;


  return 0;
}