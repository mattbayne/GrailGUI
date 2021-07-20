#include <iostream>

#include "fmt/core.h"

using namespace std;
using namespace fmt;

int main() {
  auto out = memory_buffer();
  format_to(back_inserter(out), "Hello, {}", "World!");
  cout << out.data() << " " << out.size();
}
