#include <chrono>
#include <iostream>

#include "fmt/color.h"
#include "fmt/core.h"
#include "fmt/format.h"

using namespace std;
using namespace fmt;
using namespace chrono;
char dig2[202] = {
    "00010203040506070809"
    "10111213141516171819"
    "20212223242526272829"
    "30313233343536373839"
    "40414243444546474849"
    "50515253545556575859"
    "60616263646566676869"
    "70717273747576777879"
    "80818283848586878889"
    "90919293949596979899"};

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

  tp = time_point_cast<nanoseconds>(steady_clock::now());
  for (int i = 0; i < iter; i++) {
    out = memory_buffer();
    format_to(back_inserter(out), "{}", fmt_val);
    data = out.data();  // pointer to the formatted data
    size = out.size();  // size of the formatted data
  }
  sum_time = (steady_clock::now() - tp).count();
  double avg = sum_time * 1.0 / iter;
  print("fmtlib: {}\n\n", avg);
}

void formatspf(float f) {
  uint64_t sum_time = 0;
  time_point<steady_clock, nanoseconds> tp;
  char* data = new char[30];
  uint32_t size;
  constexpr auto iter = 1000000;
  double avg = sum_time * 1.0 / iter;

  sum_time = 0;
  tp = time_point_cast<nanoseconds>(steady_clock::now());
  for (int i = 0; i < iter; i++) {
    size = sprintf(data, "%f", f);
  }
  sum_time = (steady_clock::now() - tp).count();
  avg = sum_time * 1.0 / iter;
  print("sprintf: {}\n\n", avg);
}

void formatspf(double f) {
  uint64_t sum_time = 0;
  time_point<steady_clock, nanoseconds> tp;
  char* data = new char[30];
  uint32_t size;
  constexpr auto iter = 1000000;
  double avg = sum_time * 1.0 / iter;

  sum_time = 0;
  tp = time_point_cast<nanoseconds>(steady_clock::now());
  for (int i = 0; i < iter; i++) {
    size = sprintf(data, "%lf", f);
  }
  sum_time = (steady_clock::now() - tp).count();
  avg = sum_time * 1.0 / iter;
  print("sprintf: {}\n\n", avg);
}

void formatspf(int f) {
  uint64_t sum_time = 0;
  time_point<steady_clock, nanoseconds> tp;
  char* data = new char[30];
  uint32_t size;
  constexpr auto iter = 1000000;
  double avg = sum_time * 1.0 / iter;

  sum_time = 0;
  tp = time_point_cast<nanoseconds>(steady_clock::now());
  for (int i = 0; i < iter; i++) {
    size = sprintf(data, "%d", f);
  }
  sum_time += (steady_clock::now() - tp).count();
  avg = sum_time * 1.0 / iter;
  print("sprintf: {}\n\n", avg);
}

void formatspf(uint64_t f) {
  uint64_t sum_time = 0;
  time_point<steady_clock, nanoseconds> tp;
  char* data = new char[30];
  uint32_t size;
  constexpr auto iter = 1000000;
  double avg = sum_time * 1.0 / iter;

  sum_time = 0;
  tp = time_point_cast<nanoseconds>(steady_clock::now());
  for (int i = 0; i < iter; i++) {
    size = sprintf(data, "%ld", f);
  }
  sum_time += (steady_clock::now() - tp).count();
  avg = sum_time * 1.0 / iter;
  print("sprintf: {}\n\n", avg);
}

void formatspf(const char* f) {
  uint64_t sum_time = 0;
  time_point<steady_clock, nanoseconds> tp;
  char* data = new char[30];
  uint32_t size;
  constexpr auto iter = 1000000;
  double avg = sum_time * 1.0 / iter;

  sum_time = 0;
  tp = time_point_cast<nanoseconds>(steady_clock::now());
  for (int i = 0; i < iter; i++) {
    size = sprintf(data, "%s", f);
  }
  sum_time += (steady_clock::now() - tp).count();
  avg = sum_time * 1.0 / iter;
  print("sprintf: {}\n\n", avg);
}

template <typename T>
uint32_t _formatgrl(char destBuf[33], T printVal) {
  uint32_t len;
  int i;
  for (i = 31; i >= 0; i--) {
    T temp = printVal / 10;
    uint32_t digit = printVal - temp * 10;
    destBuf[i] = '0' + digit;
    if (printVal == 0) break;
    printVal = temp;
  }
  return 31 - i;
}

template <typename T>
uint32_t _formatgrl2(char destBuf[33], T printVal) {
  uint32_t len;
  int i;
  for (i = 30; printVal >= 100; i -= 2) {
    T temp = printVal / 100;
    uint32_t digit2 = printVal - temp * 100;
    *(uint16_t*)&destBuf[i] = ((uint16_t*)dig2)[digit2];
    printVal = temp;
  }
  if (printVal >= 10) {
    *(uint16_t*)&destBuf[i] = ((uint16_t*)dig2)[printVal];
  } else if (printVal > 0) {
    destBuf[++i] = '0' + printVal;
  }
  return 32 - i;
}

template <typename T>
uint32_t _formatgrl3(char destBuf[33], T printVal) {
  uint32_t len;
  int i;
  for (i = 28; printVal >= 10000; i -= 4) {
    T temp = printVal / 10000;
    uint32_t digit4 = printVal - temp * 10000;
    uint32_t digit2 = digit4 / 100;
    *(uint16_t*)&destBuf[i + 2] = ((uint16_t*)dig2)[digit4 - digit2 * 100];
    *(uint16_t*)&destBuf[i] = ((uint16_t*)dig2)[digit2];
    printVal = temp;
  }
  if (printVal >= 100) {
    if (printVal >= 1000) {
      uint32_t digit2 = printVal / 100;
      *(uint16_t*)&destBuf[i] = ((uint16_t*)dig2)[digit2];
      *(uint16_t*)&destBuf[i + 2] = ((uint16_t*)dig2)[printVal - digit2 * 100];
    } else {
      uint32_t digit = printVal / 100;
      *(uint16_t*)&destBuf[i + 2] = ((uint16_t*)dig2)[printVal - digit * 100];
      destBuf[i += 1] = '0' + digit;
    }
  } else {
    if (printVal >= 10) {
      *(uint16_t*)&destBuf[i += 2] = ((uint16_t*)dig2)[printVal];
    } else if (printVal > 0) {
      destBuf[i += 3] = '0' + printVal;
    }
  }
  return 32 - i;
}

uint32_t _formatgrl(char destBuf[33], int printVal) {
  if (printVal < 0) {
    // TODO: this will not work for -intmax?!?
    uint32_t len = _formatgrl(destBuf, uint32_t(-printVal));
    destBuf[32 - len] = '-';
    return len + 1;
  } else {
    return _formatgrl(destBuf, uint32_t(printVal));
  }
}

template <typename T>
void formatgrl(char destBuf[33], T printVal) {
  uint32_t size;
  uint64_t sum_time = 0;
  time_point<steady_clock, nanoseconds> tp;
  constexpr auto iter = 1000000;

  tp = time_point_cast<nanoseconds>(steady_clock::now());
  for (int i = 0; i < iter; i++) {
    size = _formatgrl(destBuf, printVal);
  }
  destBuf[32] = '\0';
  print("{}\n", destBuf + 32 - size);
  sum_time += (steady_clock::now() - tp).count();
  double avg = sum_time * 1.0 / iter;
  print("grail: {}\n", avg);
}

template <typename T>
void formatgrl2(char destBuf[33], T printVal) {
  uint32_t size;
  uint64_t sum_time = 0;
  time_point<steady_clock, nanoseconds> tp;
  constexpr auto iter = 1000000;

  tp = time_point_cast<nanoseconds>(steady_clock::now());
  for (int i = 0; i < iter; i++) {
    size = _formatgrl2(destBuf, printVal);
  }
  destBuf[32] = '\0';
  print("{}\n", destBuf + 32 - size);
  sum_time += (steady_clock::now() - tp).count();
  double avg = sum_time * 1.0 / iter;
  print("grail: {}\n", avg);
}
template <typename T>
void formatgrl3(char destBuf[33], T printVal) {
  uint32_t size;
  uint64_t sum_time = 0;
  time_point<steady_clock, nanoseconds> tp;
  constexpr auto iter = 1000000;

  tp = time_point_cast<nanoseconds>(steady_clock::now());
  for (int i = 0; i < iter; i++) {
    size = _formatgrl3(destBuf, printVal);
  }
  destBuf[32] = '\0';
  print("{}\n", destBuf + 32 - size);
  sum_time += (steady_clock::now() - tp).count();
  double avg = sum_time * 1.0 / iter;
  print("grail: {}\n", avg);
}

template <typename T>
void testboth(T data) {
  test_format(data);
  formatspf(data);
}

int main() {
  char dest[33];
  testboth(1.0f);
  testboth(11);
  formatgrl(dest, 11);
  formatgrl2(dest, 11);
  formatgrl3(dest, 11);
  testboth(-134135);
  formatgrl(dest, -134135);
  formatgrl2(dest, -134135);
  formatgrl3(dest, -134135);
  testboth(135567.362626);
  testboth("hello test");
  testboth(UINT64_MAX);
  formatgrl(dest, UINT64_MAX);
  formatgrl2(dest, UINT64_MAX);
  formatgrl3(dest, UINT64_MAX);
}
