#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
bool visited[N];
int nodesNum;

void bfs(int node)
{
   queue<int> q;
   q.push(node);
   visited[node] = true;
   while (!q.empty())
   {
       node = q.front();
       cout << node << endl;
       q.pop();
       for (int child: adj[node])
           if (!visited[child])
           {
               q.push(child);
               visited[child] = true;
           }
   }
}



int main()
{
   int edges;
   cin >> nodesNum >> edges;
   while (edges--)
   {
       int x, y;
       cin >> x >> y;
       adj[x].push_back(y);
       adj[y].push_back(x);
   }
   bfs(1);
   return 0;
}
