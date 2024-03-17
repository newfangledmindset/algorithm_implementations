#include <bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int s) {
    if (visited[s]) return;
    visited[s] = true;

    //s -> e_1, e_2, ... e_i 모든 경우에 대해
    for (auto &e : adj[s]) {
        dfs(adj, visited, e);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //Directed graph
    //n: 노드 갯수, s: 시작 노드
    int x, y, n, s;

    //adjacency list
    vector<vector<int>> adj;
    vector<bool> visited(n, false);

    //x to y
    adj[x].push_back(y);

    dfs(adj, visited, s);
}