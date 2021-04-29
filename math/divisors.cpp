#include<bits/stdc++.h>

using namespace std;

vector<int> getdivisors(int n) {
    vector<int> v;
    for (int i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i != n / i)v.push_back(n / i);
        }
    }
    return v;
}

int main() {
    int d;
    cin >> d;
    vector<int> temp = getdivisors(d);

    for (auto digit:temp)cout << digit << " ";

}