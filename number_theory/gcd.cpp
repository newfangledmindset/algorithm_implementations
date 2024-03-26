#include <bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << gcd(12, 40);
}