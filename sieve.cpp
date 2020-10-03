#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 9;

bool isprime[N];

void sieve() {
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= N / i; i += 1 + (i & 1)) { //sqrt(n)
        if (isprime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isprime[j] = false;
            }
        }
    }
}

int main() {

    for (int i = 0; i < N; i++)isprime[i] = true;
    sieve();

    cout << isprime[4] << endl;
    cout << isprime[5] << endl;
    cout << isprime[6] << endl;
    cout << isprime[9] << endl;
}