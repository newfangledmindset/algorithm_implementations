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

vector<ti> edges;
vi v_link;
vi v_size;

// Union-Find 구현
int find(int x) {
    while (x != v_link[x]) {
        // path optimization
        v_link[x] = v_link[v_link[x]];
        x = v_link[x];
    }
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (v_size[a] < v_size[b]) swap(a, b);
    v_size[a] += v_size[b];
    v_link[b] = a;
}

// Kruskal's Algorithm을 이용한 MST 생성
void gen_mst() {
    /* Kruskal's Algorithm: Greedy Algorithm
     * 1. 모든 edge를 weight에 대해 정렬 (오름차순으로)
     * 2. 작은 edge부터 set에 추가
     * 3. Disjoint Set of Edges를 계속 더해간다.
     */

    sort(edges.begin(), edges.end());

    for (auto &e : edges) {
        int w, a, b;
        tie(w, a, b) = e;

        // a, b가 disjoint하면 합한다.
        if (!same(a, b)) unite(a, b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v = 100, e = 1093;

    v_link.resize(v + 1);
    v_size.resize(v + 1, 1);

    for (int i = 0; i <= v; i++) v_link[i] = i;

    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, a, b});
    }
}