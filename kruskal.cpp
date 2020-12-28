#include <bits/stdc++.h>
using namespace std;

class dsu {
public:

    vector<int> parent, size;

    dsu(int n) { //intalize dsu size
        for (int i = 0; i < n + 5; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    //can go from a to b
    bool sameComponent(int a, int b) {

        return findparent(a) == findparent(b);
    }

    //pathcompresion when finding the root
    int findparent(int node) {
        if (node == parent[node])return node;
        return parent[node] = findparent(parent[node]);;
    }

    //join node a with node b
    void join(int a, int b) {
        a = findparent(a);//first parent
        b = findparent(b);//second parent

        if (size[a] > size[b]) {
            parent[b] = a;
            size[a] += b;
        } else {
            parent[a] = b;
            size[b] += a;
        }

    }

};


int main() {
    int n, m;
    cin >> n >> m;
    dsu d(n);

    //cost of each edge and its nodes
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({c, {u, v}});
    }

    sort(edges.begin(), edges.end());

    int mincost = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (d.sameComponent(edges[i].second.first, edges[i].second.second) == false) {
            d.join(edges[i].second.first, edges[i].second.second);
            mincost += edges[i].first;
        }
    }
    cout << mincost << endl;

}
