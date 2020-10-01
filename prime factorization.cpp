#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> PrimeFactors(int n) {

    vector<pair<int, int>> temp;
    for (int i = 2; i <= n / i; i++) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        if (cnt > 0)
            temp.push_back({i, cnt});

    }
    if (n > 0)temp.push_back({n, 1});
    return temp;
}

int main() {
    int d;
    cin >> d;

    vector<pair<int, int>> temp = PrimeFactors(d);

    for (auto p :temp)cout << p.first << " " << p.second << endl;

}