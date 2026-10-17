#include <bits/stdc++.h>
using namespace std;

static double sigmoid(double x) {
    // TODO: return 1 / (1 + e^-x), without overflowing for large |x|.
    (void)x;
    return 0.0;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.find_first_not_of(" \t\r") == string::npos) continue;
        printf("%.4f\n", sigmoid(atof(line.c_str())));
    }
    return 0;
}
