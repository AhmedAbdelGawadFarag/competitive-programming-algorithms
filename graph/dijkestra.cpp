#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, inf = 2e9;

vector<pair<int, int>> graph[N];
int nodesNum;

int dijkstra(int startNode, int destination)
{
   int dist[N] = {};
   for (int i = 1; i <= nodesNum; i++)
       dist[i] = inf;
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
   pq.push({0, startNode});
   dist[startNode] = 0;
   while (!pq.empty())
   {
       int node = pq.top().second;
       int curCost = pq.top().first;
       pq.pop();
       if (curCost > dist[node])
           continue;
       for (auto it: graph[node])
       {
           int child = it.first;
           int newCost = curCost + it.second;
           if (newCost < dist[child])
           {
               pq.push({newCost, child});
               dist[child] = newCost;
           }
       }
   }
   return dist[destination];
}

int main()
{
   int edges;
   cin >> nodesNum >> edges;
   while (edges--)
   {
       int x, y, w;
       cin >> x >> y >> w;
       graph[x].push_back({y, w});
       graph[y].push_back({x, w});
   }
   cout << dijkstra(1, 3);
   return 0;
}
