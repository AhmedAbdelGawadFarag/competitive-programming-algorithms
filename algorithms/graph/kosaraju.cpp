#include<bits/stdc++.h>

using namespace std;


typedef long long ll;

vector<int> adj[150], adjR[150];
stack<int> nodes;

const int N = 2e5 + 9;
int compId[N], vis[N], vid, n, m, cntComp;
int notSrc[N], notSnk[N];

void dfs1(int u) {
    if (vis[u] == vid) return;
    vis[u] = vid;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        dfs1(v);
    }
    nodes.push(u);
}

void dfs2(int u, int id) {
    if (vis[u] == vid) return;
    vis[u] = vid;
    compId[u] = id;
    for (int i = 0; i < adjR[u].size(); ++i) {
        int v = adjR[u][i];
        dfs2(v, id);
    }
}


void Kusoraju() {
    ++vid;
    for (int i = 0; i < n; ++i) {
        if (vis[i] != vid) {
            dfs1(i);
        }
    }
    ++vid;
    cntComp = 0;
    while (!nodes.empty()) {
        int u = nodes.top();
        nodes.pop();
        if (vis[u] == vid) continue;
        dfs2(u, cntComp++);
    }
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (compId[u] == compId[v])
                continue;
            notSrc[compId[v]] = vid;
            notSnk[compId[u]] = vid;
        }
    }

}


int main() {


    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adjR[b].push_back(a);
    }

    Kusoraju();

    int cntSrc = cntComp - count(notSrc, notSrc + cntComp, vid);
    int cntSnk = cntComp - count(notSnk, notSnk + cntComp, vid);

    cout << compId[1] << endl; // see comp id of 1
    cout << compId[4] << endl; //see comp id of 4
    return 0;
}