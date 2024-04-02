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

// 행렬을 이용한 풀이, O(log n)
// 조만간 블로그 같은 데에 올리던가 해야겠다

void mult(int (*a)[2], const int (*b)[2], const int m);

// 기본적인 건 fme랑 비슷함
int ffib(int n, int m) {
    int p_mat[2][2] = {{1, 1}, {1, 0}};
    int acc_mat[2][2] = {{1, 1}, {1, 0}};
    
    while (n > 0) {
        if (n & 1) mult(acc_mat, p_mat, m);
        mult(p_mat, p_mat, m);
        n >>= 1;
    }

    return acc_mat[0][1];
}

// 행렬 곱셈
void mult(int (*a)[2], const int (*b)[2], const int m) {
    int w, x, y, z;
    w = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    x = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    y = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    z = a[1][0] * b[0][1] + a[1][1] * b[1][1];

    a[0][0] = w % m;
    a[0][1] = x % m;
    a[1][0] = y % m;
    a[1][1] = z % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    const int m = 10007;

    cout << ffib(n, m);
}