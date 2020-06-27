#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
bool visited[N];
int nodesNum;
void dfs(int node)
{
   if (visited[node])
       return;
   cout << node << endl;
   visited[node] = true;
   for (int child: adj[node])
       dfs(child);
}

int main()
{
   int edges, x, y;
   cin >> nodesNum >> edges;
   while (edges--)
   {
       cin >> x >> y;
       adj[x].push_back(y);
       adj[y].push_back(x);
   }
   dfs(1);
   return 0;
}
