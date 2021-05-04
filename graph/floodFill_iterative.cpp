#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 2500;
const int R_CHANGE[] = {0, 1, 0, -1};
const int C_CHANGE[] = {1, 0, -1, 0};

int row_num;
int col_num;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

bool valid(int r, int c) {
    if (r < 0 || r >= row_num || c < 0 || c >= col_num)return false;
    else
        return true;
}


void floodfill(int r, int c, int color) {
    stack<pair<int, int>> frontier;
    frontier.push({r, c});
    while (!frontier.empty()) {
        r = frontier.top().first;
        c = frontier.top().second;
        frontier.pop();

        if (!valid(r, c) || visited[r][c] || grid[r][c] != color)
            continue;

        visited[r][c] = true;
        for (int i = 0; i < 4; i++) {
            frontier.push({r + R_CHANGE[i], c + C_CHANGE[i]});
        }
    }
}

int main() {
    cin >> row_num >> col_num;
    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < col_num; j++) {
            cin >> grid[i][j];
        }
    }

    int components = 0;
    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < col_num; j++) {
            if (!visited[i][j]) {
                floodfill(i, j, grid[i][j]);
                components++;
            }
        }
    }
    cout << components << endl;
}