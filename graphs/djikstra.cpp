#include <bits/stdc++.h>
#define F first
#define S second
#define INF (~0U >> 2)
#define L_INF (~0LLU >> 2)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
typedef vector<int> vi;

// BFS를 응용하자
void find_shortest_path(const vector<vector<pi>>& adj, vector<bool>& visited, vi& distance, int v) {
    
    // weight을 기준으로 정렬
    auto comp = [](pi s1, pi s2) -> bool {
        return s1.S < s2.S;
    };

    // 최소 거리부터 처리하기 위한 컨테이너
    // 최적화 용도라 없어도 되긴 하는데 있으면 O(n log n)
    priority_queue<pi, vector<pi>, decltype(comp)> q(comp);

    // 시작점 push
    q.push({v, 0});
    distance[v] = 0;
    
    while (!q.empty()) {
        // 현재 노드
        auto a = q.top().F;
        q.pop();

        if (visited[a]) continue;
        visited[a] = true;

        for (auto& e : adj[a]) {
            // a -> b, with weight = w
            int b = e.F, w = e.S;
            
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;

                // -가 아니라 +면 최대 거리부터 처리됨
                q.push({b, -w});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5;
    
    // {a, b}, a: end_node, b: weight
    vector<vector<pi>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vi distance(n + 1, INF);

    adj[1].push_back({2, 5});
    adj[1].push_back({5, 1});
    adj[2].push_back({1, 5});
    adj[2].push_back({3, 2});
    adj[3].push_back({2, 2});
    adj[3].push_back({4, 6});
    adj[4].push_back({1, 9});
    adj[4].push_back({3, 6});
    adj[4].push_back({5, 2});
    adj[5].push_back({4, 2});
    adj[5].push_back({1, 1});

    find_shortest_path(adj, visited, distance, 1);

    for (const auto& d : distance) cout << d << ' ';
}