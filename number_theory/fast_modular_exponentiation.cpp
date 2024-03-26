#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

//fast modular exponentiation
//로젠책 Number Theory and Cryptography 참고

ll fme(const ll& n, const ll& _k, const ll& m) {
    ll acc = 1, pow = n % m, k = _k;
    while (k > 0) {
        if (k % 2 == 1) acc = (acc * pow) % m;
        pow = (pow * pow) % m;
        k = k >> 1;
    }
    return acc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fme(3, 644, 645); // 36
}