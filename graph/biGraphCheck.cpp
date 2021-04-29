#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 9;

bool vis[N];
bool bad = 0;
int group[N];
vector<int> graph[N];

void dfs(int n, bool g) { // check if the graph is bie graph
    vis[n] = 1;
    group[n] = g;
    for (int u:graph[n]) {
        if (vis[u]) {
            if (group[u] == g)
                bad = 1;
        } else
            dfs(u, !g);
    }
    return;
}

bool check(int startNode) {
    dfs(startNode,0);
    return (bad == 0);//true if the bad is zero
}

int main() {


}