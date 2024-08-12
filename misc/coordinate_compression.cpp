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
    
    // index arr
    vi v1 = {-100000, -100000, 1, 1, 1, 1, 2, 4, 5, 5, 5, 13124131, 123123124};

    // compressed arr
    vi c = v1;

    int n = v1.size();

    sort(c.begin(), c.end());

    c.resize(unique(c.begin(), c.end()) - c.begin());
    
    for (int i = 0; i < n; i++)
        v1[i] = lower_bound(c.begin(), c.end(), v1[i]) - c.begin();

    for (auto &x : v1) cout << x << ' ';
}