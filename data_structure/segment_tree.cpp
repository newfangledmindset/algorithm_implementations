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

constexpr int n = 5;

// Size of a segment tree: '최대' 4 * n
int t[4 * n];

// v: 현재 노드
void build(int a[], int v, int tl, int tr) {
    // Leaf node
    if (tl == tr) t[v] = a[tl];
    else {
        // Left child: [tl, tm], Right child:[tm + 1, tr]
        int tm = (tl + tr) / 2;

        // Left chlid 방문
        build(a, v * 2, tl, tm);

        // Right child 방문
        build(a, v * 2 + 1, tm + 1, tr);

        // v: Parent, v * 2: Left child, v * 2 + 1: Right child
        // children의 합이 parent node의 값
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    // [l, r]: query 범위, [tl, tr]: Segment tree에서의 범위
    if (l > r) return 0;

    // Case 1: [l, r] == [tl, tr]
    if (l == tl && r == tr) return t[v];

    // Case 2, 3: [l, r]이 [tl, tr]에 포함됨
    int tm = (tl + tr) / 2;

    // Case 2, 3 구분 안하고 둘 다 방문 시도 (invalid해도 첫줄에서 걸러짐)
    return query(v * 2, tl, tm, l, min(r, tm))
        + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int val) {
    // Leaf node에 대해
    if (tl == tr) t[v] = val;
    else {
        int tm = (tl + tr) / 2;

        // Left child 방문
        if (pos <= tm) update(v * 2, tl, tm, pos, val);
        // Right child 방문
        else update(v * 2 + 1, tm + 1, tr, pos, val);

        // post-order => leaf node에서부터 올라오게
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v1[5] = { 1, 3, -2, 8, -7 };
    build(v1, 1, 0, n - 1);

    // A: -2 + 8 + 7 = -1
    cout << query(1, 0, n - 1, 2, 4) << '\n';

    // v1[2] = 3 으로 업데이트
    update(1, 0, n - 1, 2, 3);
    
    // A: 3 + 8 + -7 = 4
    cout << query(1, 0, n - 1, 2, 4);
}