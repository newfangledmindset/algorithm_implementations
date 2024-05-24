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

/*
 * Tree는 acyclic하고 특정 노드로의 경로가 하나뿐이므로 아래와 같은 approach가 가능
 */
// s: 현재 노드, prev: 과거 노드 (즉, 부모 노드)

void dfs(int s, int prev) {
    // s의 모든 자식 노드에 대해
    for (auto e : adj[s]) {
        // undirected graph이므로 자식 -> 부모 노드로 가는 가능성 존재
        // 그럴 가능성을 없애기 위해 자식 -> 부모 노드로 갈 때 continue
        if (e == prev) continue;
        dfs(e, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}