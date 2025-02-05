#include "base64.h"
#include <iostream>

int main() {
  using namespace std;
  vector<denko::byte_t> s{'A'};
  cout << denko::base64::encode(s) << endl;
  return 0;
}