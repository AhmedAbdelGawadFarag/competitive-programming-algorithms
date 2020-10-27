#include <bits/stdc++.h>

using namespace std;

//a b
//d c
//i ,j is the upper left point = a
//k,l is the lower right point = c
int sumrange(int i, int j, int k, int l, vector<vector<int>> &v) {
    return v[k][l] - v[k][j - 1] - v[i - 1][l] + v[i - 1][j - 1];
}

int main() {

    int rows, colms;
    cin >> rows >> colms;
    vector<vector<int>> v(rows + 1, vector<int>());//intalize 2d vector


    v[0].resize(colms + 1, 0);//intalize first row with zeros
    for (int i = 1; i <= rows; i++) {
        v[i].resize(colms + 1, 0);
        for (int j = 1; j <= colms; j++) {
            cin >> v[i][j];
        }
    }

    //sum rows
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= colms; j++) {
            v[i][j] += v[i][j - 1];
        }
    }


    for (int i = 1; i <= colms; i++) {
        for (int j = 1; j <= rows; j++) {
            v[j][i] += v[j - 1][i];
        }
    }

    cout << sumrange(1, 3, 2, 4, v);

}
