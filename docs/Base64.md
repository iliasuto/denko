# Introduction

This library "libdenko.a" provides tools for Base64 decoding and encoding.

Include header `denko/base64.h`.

# Quick Start

**How to encode text to base64**
```cpp
// encode ( string -> string )
string data("HELLO");
string encoded = denko::Base64::encode(data);
cout << encoded << endl; // SEVMTE8=
```

**How to decode base64 to text**
```cpp
// decode ( string -> string )
string encoded("SEVMTE8=");
string decoded = denko::Base64::decode(encoded);
cout << decoded << endl; // HELLO
```

# Some Base64 function

```cpp
/// @brief Sentinel representing on invalid string.
static const std::string NONE;

/// @brief encode ( string -> string )
/// @param origin_data the string to encode to.
/// @return return encoded string.
static std::string encode(const std::string &origin_data);

/// @brief decode ( string -> string )
/// @param encoded_data the string to decode to.
/// @return return decoded string. if failed Base64::NONE.
static std::string decode(const std::string &encoded_data);

/// @brief encode (file -> string)
/// @param in_file the filename to encode to.
/// @return return encoded string.
static std::string encode_file(const std::string &in_file);

/// @brief decode (file -> string)
/// @param in_file the filename to decode to.
/// @return return decoded string. if failed Base64::NONE.
static std::string decode_file(const std::string &in_file);
```

# A exmple for test denko::Base64

```cpp
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
```

# More examples

see [examples](https://github.com/iliasuto/denko/tree/main/examples)
