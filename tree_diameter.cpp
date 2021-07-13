#include <bits/stdc++.h>

using namespace std;


const int N = 1e3;


vector<int> graph[N];
bool isvisted[N];

//dfs to get farthest node
void dfsutil(int node, int currlength, int &MaxLength, int &farthestNode) {

    if (MaxLength < currlength) {
        MaxLength = currlength;
        farthestNode = node;
    }

    isvisted[node] = true;

    for (auto child : graph[node]) {
        if (!isvisted[child])
            dfsutil(child, currlength + 1, MaxLength, farthestNode);
    }

}

//dfs to get farthest node and count of edges to get to this farthest node
pair<int, int> dfs(int node) {

    int maxNodeCount = -1;
    int farthestnode = -1;
    dfsutil(node, 0, maxNodeCount, farthestnode);

    return {maxNodeCount, farthestnode};
}

// get max length of path between two nodes
// start from random node
// then do two dfs
int treeDiamter(int node) {
    pair<int, int> p = dfs(node);//dfs from first arbitrary node


    fill(isvisted, isvisted + N, false); // clear visited array


    // dfs from farthest node from the first arbitrary node
    pair<int, int> p2 = dfs(p.second);

    //return max length of path
    return p2.first;
}

int main() {


    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // choose arbitrary node
    cout << treeDiamter(3);

}