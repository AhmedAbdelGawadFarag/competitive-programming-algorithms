#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct mi {
    int v;

    explicit operator int() const { return v; }

    mi() { v = 0; }

    mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};

mi &operator+=(mi &a, mi b) {
    if ((a.v += b.v) >= MOD) a.v -= MOD;
    return a;
}

mi &operator-=(mi &a, mi b) {
    if ((a.v -= b.v) < 0) a.v += MOD;
    return a;
}

mi operator+(mi a, mi b) { return a += b; }

mi operator-(mi a, mi b) { return a -= b; }

mi operator*(mi a, mi b) { return mi((long long) a.v * b.v); }

mi &operator*=(mi &a, mi b) { return a = a * b; }

mi pow(mi a, long long p) {
    assert(p >= 0);
    return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}

mi inv(mi a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
}

mi operator/(mi a, mi b) { return a * inv(b); }

int main() {
    mi a = 1e8, b = 1e8, c = 1e8; // with taking mod
    cout << (a * b * c).v << "\n";  // 49000000
}
