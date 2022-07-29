#include <bits/stdc++.h>
using namespace std;

void move1step(int& a, int& b, const int& q){
    int c = a - q*b;
    a = b;
    b = c;
}

int eGCD(int r0, int r1, int& x0, int& y0){
    int x1 = y0 = 0, y1 = x0 = 1;
    while(r1){
        int q = r0/r1;
        move1step(r0, r1, q);
        move1step(x0, x1, q);
        move1step(y0, y1, q);
    }
    return r0;
}

int main( ) 
{
	int X, Y;
	cout << eGCD(3, 7, X, Y) << endl;
	cout << X <<  ' ' << Y << endl;
	return 0;   
}
