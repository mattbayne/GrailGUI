#include <chrono>
#include <iostream>

#include "fmt/color.h"
#include "fmt/core.h"
#include "fmt/format.h"

using namespace std;
using namespace fmt;
using namespace chrono;

template <typename T>
void test_format(T fmt_val) {
  print(fg(color::steel_blue) | emphasis::bold, "Currently processing: {}\n",
        fmt_val);
  uint64_t sum_time = 0;
  time_point<steady_clock, nanoseconds> tp;
  memory_buffer out;
  char* data = new char[30];
  uint32_t size;
  constexpr auto iter = 1000000;

  for (int i = 0; i < iter; i++) {
    tp = time_point_cast<nanoseconds>(steady_clock::now());
    out = memory_buffer();
    format_to(back_inserter(out), "For a moment, {} happened. {}", "nothing",
              28);
    data = out.data();  // pointer to the formatted data
    size = out.size();  // size of the formatted data
    sum_time += (steady_clock::now() - tp).count();
  }

  double avg = sum_time * 1.0 / iter;
  print("fmtlib/fmt: {}\n", avg);

  sum_time = 0;
  for (int i = 0; i < iter; i++) {
    tp = time_point_cast<nanoseconds>(steady_clock::now());
    sprintf(data, "For a moment, %s happened. %d", "nothing", 28);
    size = strlen(data);
    sum_time += (steady_clock::now() - tp).count();
  }
  avg = sum_time * 1.0 / iter;
  print("sprintf: {}\n\n", avg);
}

int main() {
  test_format(1.0f);
  auto a = 11;
  test_format(11);
  test_format(-134135);
  test_format(135567.362626);
  test_format(string("hello test").c_str());
  test_format(string("irjaoijofijfr"));
}
