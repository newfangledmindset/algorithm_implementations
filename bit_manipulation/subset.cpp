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

string bit_to_string(int s, int n) {
    string res = "";
    for (int i = n - 1; i >= 0; i--) {
        bool r = (s & (1 << i));
        res += r + '0';
    }
    return res;
}

void iterate_through_subset(int s, int k, int n) {
    // s: 전체 set, k: element의 개수, n: s의 길이
    // a: s의 subset
    int a = 0;

    do {
        if (__builtin_popcount(a) == k) {
            cout << bit_to_string(a, n) << '\n';
        }
    } while (a = (a - s) & s);
}

void inverse_set(int s, int n) {
    // s: 전체 set, n: s의 길이
    for (int i = 0; i < n; i++) s ^= (1 << i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10;

    // s: 전체 set
    int s = (1 << n) - 1;
    
    iterate_through_subset(s, 3, n);
}