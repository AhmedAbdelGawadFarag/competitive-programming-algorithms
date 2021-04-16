#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define endl "\n"

const int N = 1e7 + 9;

int factor[N];
ll summ[N];
ll ans[N];

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
    for (int i = 0; i < N; i++) {
        summ[i] = 1;
        ans[i] = -1;
    }

}

int main() {

    ios_base::sync_with_stdio(false), cin.tie(NULL);


    modifiedSieve();

    //summ of divisord of integers 1...N
    for (int i = 2; i < N; i++) {
        int num = i;

        int currmul = 1;
        int currsum = 1;
        while (num % factor[i] == 0) {
            num /= factor[i];
            currmul *= factor[i];
            currsum += currmul;
        }
        summ[i] = summ[num] * currsum;
    }
    int d;
    cin >> d;
    cout << d << endl;

}