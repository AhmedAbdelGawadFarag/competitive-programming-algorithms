#include <bits/stdc++.h>

using namespace std;

int adjm[1000][1000];

int main() {

    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    //intalize matrix with large number and  node to itself with 0
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (i == j)adjm[i][j] = 0;
            else
                adjm[i][j] = 1e8;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adjm[u][v] = cost;
    }

    //floyd
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjm[i][k] < 1e8 && adjm[k][j] < 1e8)
                    adjm[i][j] = min(adjm[i][j], adjm[i][k] + adjm[k][j]);
            }
        }
    }

    int from, to;
    cin >> from >> to;
    cout << adjm[from][to] << endl;


}
