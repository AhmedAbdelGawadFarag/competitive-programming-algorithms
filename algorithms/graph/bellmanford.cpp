#include <bits/stdc++.h>

using namespace std;

#define endl "\n"


class edge {
public:
    int to, from, cost;
} edges[1000];

int dist[1000];

int n, m;

void bellmanford(int src) {
    fill(dist, dist + 1000, 1e8);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        bool en = false;

        for (int j = 0; j < m; j++) {
            if (dist[edges[j].from] < 1e8) {
                dist[edges[j].to] = min(dist[edges[j].to], dist[edges[j].from] + edges[j].cost);
                en = true;
            }
        }

        if (!en)break;//if there is no relaxiation break
    }

}

int main() {

    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges[i].from = u;
        edges[i].to = v;
        edges[i].cost = cost;
    }
    int start, end;
    cin >> start >> end;
    bellmanford(start);
    cout << dist[end] << endl;
}
