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

void find_shortest_path(const vector<ti>& paths, vector<int>& distance, int v) {
    // 모든 distance를 INF로 초기화
    for (int i = 1; i <= distance.size() - 1; i++) distance[i] = INF;

    // 시작 노드만 distance = 0
    distance[v] = 0;

    // n - 1만큼 반복
    // n만큼 반복하면 negative cycle 구하는데 쓸 수 있다
    for (int i = 1; i <= distance.size() - 2; i++) {
        for (auto& e : paths) {
            int a, b, w;
            tie(a, b, w) = e;

            // (이전 노드의 거리 + weight)이 기존 거리보다 작으면 업데이트
            distance[b] = min(distance[b], distance[a] + w);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 6;
    vector<int> distance(n + 1);
    // path는 tuple<int> (start_node, end_node, weight)
    vector<ti> paths;
    
    paths.push_back({1, 2, 5});
    paths.push_back({2, 1, 5});
    paths.push_back({1, 3, 3});
    paths.push_back({3, 1, 3});
    paths.push_back({1, 4, 7});
    paths.push_back({4, 1, 7});
    paths.push_back({3, 4, 1});
    paths.push_back({4, 3, 1});
    paths.push_back({4, 2, 3});
    paths.push_back({2, 4, 3});
    paths.push_back({2, 6, 2});
    paths.push_back({6, 2, 2});
    paths.push_back({4, 6, 2});
    paths.push_back({6, 4, 2});

    find_shortest_path(paths, distance, 1);

    for (auto& d : distance) cout << d << ' ';
}