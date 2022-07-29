#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;

int grid[MAX_N][MAX_N];  // the grid itself
int row_num;
int col_num;
bool visited[MAX_N][MAX_N];  // keeps track of which nodes have been visited

bool valid(int r, int c) {
    if (r < 0 || r >= row_num || c < 0 || c >= col_num)return false;
    else
        return true;
}

void floodfill(int r, int c, int color) {
    if (!valid(r, c) || grid[r][c] != color || visited[r][c])
        return;

    visited[r][c] = true; // mark current square as visited

    // recursively call floodfill for neighboring squares
    floodfill(r, c + 1, color);
    floodfill(r, c - 1, color);
    floodfill(r - 1, c, color);
    floodfill(r + 1, c, color);

    return;
}

int main() {
    cin >> row_num >> col_num;

    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < col_num; j++) {
            cin >> grid[i][j];
        }
    }
    int Components = 0;
    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < col_num; j++) {
            if (!visited[i][j]) {
                floodfill(i, j, grid[i][j]);
                Components++;
            }
        }
    }

    cout << Components << endl;
    return 0;
}
