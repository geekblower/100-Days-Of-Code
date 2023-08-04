#include <bits/stdc++.h>

bool isCycleBFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int Node) {
    unordered_map<int, int> parent;
    parent[Node] = -1;

    queue<int> Q;
    Q.push(Node);
    visited[Node] = true;

    while(!Q.empty()) {
        int val = Q.front();
        Q.pop();
        visited[val] = true;

        for(auto i : adjList[val]) {
            if(visited[i] == true && parent[val] != i) {
                return true;
            }

            if(visited[i] == false) {
                visited[i] = true;
                parent[i] = val;
                Q.push(i);
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=0; i<n; i++) {
        if(visited[i] == false) {
            bool ans = isCycleBFS(adjList, visited, i);

            if(ans) {
                return "Yes";
            }
        }
    }

    return "No";
}

