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

vector<vector<pi>> adj;
vi dist;

// Djikstra인데 w = {0, 1} 일 때
// Priority queue를 써도 무방하지만 약간 오버킬인 감이 있음
// edge가 {b, w} 일 때, 
// priority_queue: [{b_1, 0}, {b_2, 0}, ... , {b_i, 0}, {b_(i + 1), 1}, ...]
// 그러면 queue 왼쪽엔 w = 0인 edge를, 오른쪽엔 w = 1인 edge를 넣으면 되지 않을까?

void bfs(const int &x) {
    // 양쪽에 element를 넣을 것이기 때문에 deque가 적절함
    deque<int> q;
    q.push_front(x);
    dist[x] = 0; // Initialization

    // Djikstra 처럼
    while (!q.empty()) {
        auto a = q.front();
        q.pop_front();

        for (auto &e : adj[a]) {
            int b = e.F, w = e.S;

            // min-dist 일 때
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;

                // queue 왼쪽엔 w = 0인 edge를, 오른쪽엔 w = 1 edge를 push
                if (w == 1) q.push_back(b);
                else q.push_front(b);
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    bfs();
}