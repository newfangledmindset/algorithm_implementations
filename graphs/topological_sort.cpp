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

vector<vi> adj;
vector<char> visited;
vi res_rev;

/*
0. DAG만 가능

1. 모든 노드에 대해 dfs 수행
2. Leaf 노드를 만나면 return
3. 노드 저장

!!! 반드시 return -> 노드 저장임 (Backtrack...)
*/

void dfs(const int &a) {
    if (visited[a]) return;
    visited[a] = true;
    
    for (const auto &b : adj[a]) dfs(b);
    // res_rev에 반대 순서로 저장됨
    res_rev.push_back(a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // 모든 node에 대하여 dfs
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(i);
    }

    // 반대 순서로 정렬되었으므로
    for (int i = res_rev.size() - 1; i >= 0; i--)
        cout << res_rev[i] << ' ';
}