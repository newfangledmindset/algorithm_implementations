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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 100;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int x = 2; x * x <= n; x++) {
        if (!is_prime[x]) continue; // 소수 아니면 continue
        for (int k = x * x; k <= n; k += x) { // x * x보다 작은 값들은 이미 sift됨 (즉, 걸러졌음)
            is_prime[k] = false; // x의 배수는 모두 합성수
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) cout << i << ' ';
    }

    // O(n*log(log n))
}