# Introduction

This library "libdenko-base64.a" provides tools for Base64 decoding and encoding.

Include header `denko/base64.h`.

# How to encode text to base64

```cpp
// encode ( string -> string )
string data("HELLO");
string encoded = denko::Base64::encode(data);
cout << encoded << endl; // SEVMTE8=
```

# How to decode base64 to text
```cpp
// decode ( string -> string )
string encoded("SEVMTE8=");
string decoded = denko::Base64::decode(encoded);
cout << decoded << endl; // HELLO
```

# A exmple for test decode::Base64

```cpp

#include "denko/base64.h"
#include <iostream>

int main() {
  using namespace std;
  vector<string> data{"HELLO", "HelloWorld", "A", "你好世界",
                      "棕色狐狸散りぬる რაფրաλώσσжеγαThe123우가😀"};
  vector<string> expected{
      "SEVMTE8=", "SGVsbG9Xb3JsZA==", "QQ==", "5L2g5aW95LiW55WM",
      "5qOV6Imy54uQ54u45pWj44KK44Gs44KLIOGDoOGDkOGDpNaA1aHOu8+"
      "Oz4PPg9C20LXOs86xVGhlMTIz7Jqw6rCA8J+YgA=="};

  size_t length = data.size();
  for (size_t i = 0; i < length; ++i) {
    string origin = data[i];
    string correct = expected[i];
    string encoded = denko::Base64::encode(origin);
    string decoded = denko::Base64::decode(encoded);

    cout << "origin : " << origin << '\n';
    cout << "correct: " << correct << '\n';
    cout << "encoded: " << encoded << '\n';
    cout << "decoded: " << decoded << '\n' << endl;
  }

  return 0;
}
```