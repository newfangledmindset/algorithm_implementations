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

int find(vi &ds, int x) {
    while (x != ds[x]) x = ds[x];

    return x;
}

bool same(vi &ds, int a, int b) {
    return find(ds, a) == find(ds, b);
}

void unite(vi &ds, vi &size, int a, int b) {
    a = find(ds, a), b = find(ds, b);
    // Assume a.size >= b.size
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    ds[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 8;
    vi ds(n + 1);
    vi size(n + 1, 1);
    for (int i = 0; i <= n; i++) ds[i] = i;

    unite(ds, size, 1, 4);
    unite(ds, size, 4, 7);
    unite(ds, size, 2, 3);
    unite(ds, size, 3, 6);
    unite(ds, size, 6, 8);

    

    for (auto &x : ds) cout << x << ' ';
    cout << '\n';
    for (auto &x : size) cout << x << ' ';
    cout << '\n';
    cout << size[find(ds, 6)];
}