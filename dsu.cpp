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
    dsu d(5);//intalize with 5 elemnt
    int u, v;//node u and node v
    if (d.sameComponent(u, v) == false)//if there is no path form u to v then join them
        d.join(u, v);


}
