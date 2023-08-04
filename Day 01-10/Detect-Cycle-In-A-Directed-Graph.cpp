#include <bits/stdc++.h>

bool isCyclic(int node, unordered_map<int, list<int> > &adjList, vector<bool> &visited, vector<bool> &dfsVisited, int n) {
  visited[node] = dfsVisited[node] = true;

  for(int neigh : adjList[node]) {
    if(visited[neigh] == false) {
      bool ans = isCyclic(neigh, adjList, visited, dfsVisited, n);

      if(ans) {
        return true;
      }
    } else if(dfsVisited[neigh]) {
      return true;
    }
  }

  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, list<int> > adjList;
  for(int i=0; i<edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    adjList[u].push_back(v);
  }

  vector<bool> visited(n,false);
  vector<bool> dfsVisited(n,false);

  for(int i=0; i<n; i++) {
    if(visited[i] == false) {
      bool ans = isCyclic(i, adjList, visited, dfsVisited, n);

      if(ans) {
        return true;
      }
    }
  }

  return false;
}
