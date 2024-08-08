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

constexpr int N = 1e4;
int n;
int t[2 * N];

// init-index: 1

void build(int v1[]) {
    // Leaf node
    for (int i = 0; i < n; i++) t[i + n] = v1[i];
    // Left child + Right child
    // t[i << 1] + t[i << 1 | 1] is equiv. to t[2 * i] + t[2 * i + 1]
    for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
}

void update(int p, int val) {
    // 현재 node의 parent에 대해서만 update하면 됨
    /*
        1. t[p += n]: v1[p]에 해당하는 Leaf node
        2. p >>= 1: parent node 방문
        3. t[p >> 1] = t[p] + t[p ^ 1]
            t[p >> 1]: segment tree t에서 p의 parent
            t[p]: parent의 child (현재 노드)
            t[p ^ 1]: parent의 child (p 옆에 있는 node, 후술)

        4. p ^ 1: p가 left, right node인지 구분하지 않고 p의 sibling node를 나타냄
    */ 
    
    for (t[p += n] = val; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

int query(int l, int r) {
    // [l, r)에 대한 query
    int res = 0;

    /*
        1. l += n, r += n: l, r에 해당하는 Leaf node
        2. l >>= 1, r >>= 1: parent를 계속 방문
        3. if (l & 1) res += t[l++]
            1. l & 1: l이 홀수이면, l은 parent의 right child이다.
                -> l은 포함하되 parent는 제외
            2. l++: (l + 1) / 2
                -> parent 대신 [parent + 1] node를 방문

    */ 

    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += t[l++];
        if (r & 1) res += t[--r];
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    n = 5;

    int v1[n] = { 1, 3, -2, 8, -7 };
    build(v1);

    // A: -2 + 8 + 7 = -1
    cout << query(2, 5) << '\n';

    // v1[2] = 3 으로 업데이트
    update(2, 3);
    
    // A: 3 + 8 + -7 = 4
    cout << query(2, 5) << '\n';
}