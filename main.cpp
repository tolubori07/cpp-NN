#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

static string f4(double x) {
  char b[400];
  snprintf(b, sizeof b, "%.4f", x);
  return string(b);
}

static vector<double> floats(const string &s) {
  vector<double> out;
  stringstream ss(s);
  string tok;
  while (getline(ss, tok, ','))
    out.push_back(atof(tok.c_str()));
  return out;
}

static double sigmoid(double x) {
  if (x < 0) {
    return exp(x) / (1 + exp(x));
  }
  return 1 / (1 + exp(-x));
}

static double neuron(const vector<double> &x, const vector<double> &w,
                     double b) {
  // TODO: z = w . x + b (add the products left to right), then return
  // sigmoid(z).
  double z = b;
  for (int count = 0; count < x.size(); count++) {
    z += x[count] * w[count];
  }
  return sigmoid(z);
}

int main(void) {
  string line;
  while (getline(cin, line)) {
    if (line.find_first_not_of(" \t\r") == string::npos)
      continue;
    size_t p1 = line.find(';');
    size_t p2 = line.find(';', p1 + 1);
    vector<double> x = floats(line.substr(0, p1));
    vector<double> w = floats(line.substr(p1 + 1, p2 - p1 - 1));
    double b = atof(line.substr(p2 + 1).c_str());
    printf("%s\n", f4(neuron(x, w, b)).c_str());
  }
  return 0;
}
