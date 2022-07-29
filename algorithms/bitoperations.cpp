#include <bits/stdc++.h>
using namespace std;

void setbit(int indx, int &mask) {
    mask |= (1 << indx);
}

void clearbit(int indx, int &mask) {// can do it with xor or and
    int a = ~(1 << indx);//reverse 0001000 ----> 1110111
    mask &= a;
}

void togglebit(int indx, int &mask) {//xor
    mask ^= (1 << indx);
}

bool isset(int indx, int mask) {
    return (mask & (1 << indx));
}

int main() {

    int mask = 5;//000101
    cout << isset(1, mask) << endl;
    setbit(1, mask);
    cout << isset(1, mask) << endl;

    clearbit(1, mask);
    cout << isset(1, mask) << endl;

    togglebit(1, mask);
    cout << isset(1, mask) << endl;

    togglebit(1, mask);
    cout << isset(1, mask);

}
