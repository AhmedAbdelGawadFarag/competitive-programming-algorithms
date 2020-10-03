#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int N = 2e5 + 9;

int factor[N];

void modifiedSieve() {
    iota(factor, factor + N, 0);
    factor[0] = factor[1] = 1;

    for (int i = 2; i < N / i; i += 1 + (1 & i)) {
        if (factor[i] == i) {// prime
            for (int j = i * i; j < N; j += i) {
                if (factor[j] == j) {//not visited still have his factor
                    factor[j] = i;
                }
            }
        }
    }

}

void factfast(int x) {// get prime factoraztion in o(log n)

    while (x > 1) {
        cout << factor[x] << endl;
        x /= factor[x];
    }

}

int main() {

    ios_base::sync_with_stdio(false), cin.tie(NULL);
    modifiedSieve();
    int d;
    cin >> d;
    factfast(d);

}