// find lcm over a range of integers 
// the answer will overflow so we moded it as the problem said

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    vector<int> v;
   #define mod 1000000007

   ll fp(ll base, ll exp) {
    if (exp == 0)
        return 1;
    ll ans = fp(base, exp / 2);
    ans = (ans * ans) % mod;
    if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
    return ans;
}

void GetPrime(ll a) {
    map<ll, ll> m1;

    for (ll i = 2; i * i <= a; i++) {
        while (a % i == 0) {
            m1[i]++;
            a /= i;
        }
    }
    if (a > 1)m1[a]++;


    for (auto s = m1.begin(); s != m1.end(); s++) {
        ll dig = s->first;
        ll poww = s->second;
        if (m[dig] != 0) {
            m[dig] = max(poww, m[dig]);

        } else {
            m[dig] = poww;

        }

    }


}

ll GetLCM() {
    ll ans = 1;
    for (auto s = m.begin(); s != m.end(); s++) {
        ans = (ans * fp(s->first, s->second)) % mod;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    v.resize(n);
    forn(i,n){
        cin>>v[i];
    }
    forn(i,n){
        getprime(v[i]);
    }
    getLCM();

}