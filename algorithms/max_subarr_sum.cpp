#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// kadane's algorithm

int max_subarray_sum(vector<int> &v) {

    int current_sum = v[0];
    int max_subarray_sum = v[0];
    for (int i = 1; i < v.size(); i++) {
        current_sum = max(current_sum + v[i], v[i]);
        max_subarray_sum = max(max_subarray_sum, current_sum);
    }

    return max_subarray_sum;

}

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << max_subarray_sum(x);

}