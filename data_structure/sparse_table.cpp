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

constexpr int K = 25;
constexpr int MAX_N = 1e6 + 1;

/**
 * Sparse Table
 * Idempotent function에 대해, range query를 O(1)에 처리 가능.
 * >> Idempotent function: f(f(x)) = f(x) 인 function
 * 
 * Preprocessing: O(n log n)
 * Range Query: O(1) for idempotent functions.
 */

// st[i][j]: Range query for [j, j + {2 ^ i} - 1]
int st[K][MAX_N];

/*
 * [j, j + (2 ^ i) - 1] 아래와 같이 2개의 range로 분할 가능 (Divide-and-Conquer)
 *
 * [j, j + (2 ^ i) - 1] -> [j, j + {2 ^ (i - 1)} - 1] 
 *                      -> [j + {2 ^ (i - 1)}, j + 2 ^ i - 1] 
 *
 */
void preprocess() {
    // DP Approach
    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= N; j++)
            // 여기선 idempotent 함수로 min을 썼다
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1)) - 1]);
}

int log_2(const ll i) {
    // C++20
    // return bit_width(i) - 1;
    return i ? __builtin_clzll(1) - __builtin_clzll(i) - 1 : -1;
}

int min_query(const int L, const int R) {
    // i: exponent
    int i = log_2(R - L + 1);

    // st[i][L] => [L, L + (2 ^ i) - 1]
    // st[i][R - (2 ^ i) + 1] => [R - (2 ^ i) + 1, R] // - (2 ^ i) + 1 + (2 ^ i) - 1 = 0
    return min(st[i][L], st[i][R - (1 << i) + 1]);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    preprocess();

    // For [L, R]
    int L, R;
    
    int res = min_query(L, R);
}