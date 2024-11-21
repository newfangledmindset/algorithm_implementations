#include <bits/stdc++.h>
#define F first
#define S second
#define INF (~0U >> 2)
#define L_INF (~0LLU >> 2)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> ti;
typedef vector<int> vi;

constexpr int N = 1e5;
ll tree[N * 4]; // Segment tree
vector<ll> v1(N);

ll build(vector<ll> &input, int v, int l, int r) {
    if (l == r) return tree[v] = input[l];
    int m = (l + r) / 2;
    return tree[v] = build(input, v * 2, l, m) + build(input, v * 2 + 1, m + 1, r);
}

ll query(int v, int l, int r, const int wl, const int wr) {
    if (l > wr || r < wl) return 0; // Identity
    if (l >= wl && r <= wr) return tree[v]; // Total overlap
    int m = (l + r) / 2;
    return query(v * 2, l, m, wl, wr) + query(v * 2 + 1, m + 1, r, wl, wr);
}

ll update(int v, int l, int r, const int pos, const int val) {
    if (pos < l || pos > r) return tree[v];
    if (pos == l && pos == r) return tree[v] = val;
    int m = (l + r) / 2;
    return tree[v] = update(v * 2, l, m, pos, val) + update(v * 2 + 1, m + 1, r, pos, val);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> v1[i];

    build(v1, 1, 0, n - 1);

    int q = m + k;
    while (q--) {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1) update(1, 0, n - 1, a - 1, b);
        else cout << query(1, 0, n - 1, a - 1, b - 1) << '\n';
    }
}