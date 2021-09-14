#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define  pi  acos(-1)
 
const ll mod = 1000000007;
const ld EPS = 1e-9;
const int N = 2e5 + 9;
 
//          U   R  D  L
int dx[] = {-1, 0, 1, 0, -1, +1, +1, -1}; // dx for the 8 adjacent places in matrix
int dy[] = {0, 1, 0, -1, +1, +1, -1, -1};// dy for the 8 adjacent places in matrix
int main() {
 
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    //find biggest gcd betwwen two integers in array
 
    int n;
    cin >> n;
 
    vector<int> v(n);
    vector<int> freq(1000009, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        freq[v[i]]++;
    }
 
 
    //complexity ====> o(max(x) * log(max(x))
    int ans = 1;
    for (int g = 1000009; g >= 1; g--) {//gcd
        int cnt = 0;
        for (int i = g; i <= 1000009; i += g) {
            cnt += freq[i];
        }
        if (cnt >= 2) {
            ans = g;
            break;
        }
    }
 
    cout << ans << endl;
 
}
