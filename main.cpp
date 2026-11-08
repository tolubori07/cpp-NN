#include <cmath>
#include <stdio.h>
#include <stdlib.h>

static double sigmoid(double x) {
  if (x < 0) {
    return std::exp(x) / (1 + std::exp(x));
  }
  return 1 / (1 + std::exp(-x));
  return 0.0;
}

int main(void) {
  char line[512];
  while (fgets(line, sizeof line, stdin)) {
    char *end;
    double x = strtod(line, &end);
    if (end == line)
      continue; /* blank line */
    printf("%.4f\n", sigmoid(x));
  }
  return 0;
}
