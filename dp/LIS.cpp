#include <bits/stdc++.h>

using namespace std;


int find_lis(vector<int> &a) {
    vector<int> dp;
    for (int i : a) {
        int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (pos == dp.size())  // we can have a new, longer increasing subsequence!
            dp.push_back(i);
        else  // oh ok, at least we can make the ending element smaller
            dp[pos] = i;
    }
    return dp.size();
}


int main() {

    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    vector<int> b = {0, 8, 4, 12, 2, 10, 6, 14};


    cout << find_lis(b);

}