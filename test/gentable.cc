#include <cmath>
#include <cstdint>
#include <cstdio>

using namespace std;

void generateExponentsFloat(FILE* f) {
  fprintf(f, "double fpScales[] = {\n");
  for (int ex = -10; ex <= 10; ex++) {
    uint32_t powOf10 = (uint32_t)ceil(ex / log2(10.0));
    double scale = 1.0 / pow(10, powOf10 - 15);

    fprintf(f, "%lf,\n", scale);
  }
  fprintf(f, "}\n");
}

void generate4Digits(FILE* f) {
  fprintf(f, "char dig4[] = \"");
  for (int i = 0; i < 10000; i++) {
    fprintf(f, "%04d", i);
  }
  fprintf(f, "\";\n");
}

int main() {
  FILE* f = fopen("digittest.h", "w");
  generateExponentsFloat(f);

  fclose(f);
}