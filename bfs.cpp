#include <bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

void bfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &distance, queue<int> q, int s) {
    // 시작 노드 처리
    visited[s] = true;
    q.push(s);
    
    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        // current_node -> e_1, e_2, ..., e_i 모든 경우에 대해
        for (auto &e : adj[current_node]) {
            if (visited[e]) continue;
            visited[e] = true;
            //Weight 없으면 지금 노드 거리 + 1
            distance[e] = distance[current_node] + 1;
            q.push(e);
        }
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

    //distance 필요 없으면 bfs 왜 씀
    vector<int> distance(n, 0);

    //bfs는 큐 필요함
    queue<int> q;

    //x to y
    adj[x].push_back(y);

    bfs(adj, visited, distance, q, s);
}