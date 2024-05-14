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

int xgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = xgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int modulo_inverse(int a, int m) {
    int x, y;
    int d = xgcd(a, m, x, y);
    if (d != 1) return -1; // 서로소일때만 unique inverse가 존재
    return (x % m + m) % m; // ax + my = 1에서 x가 a의 inverse
    // (x % m + m) % m => remainder를 양수로...
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a = 51, m = 100;
    cout << (51 * 51) % 100 << '\n';
    cout << modulo_inverse(a, m);
}