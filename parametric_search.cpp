#include <bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

bool some_statement(int n) {
    if (n) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c, t;
    cin >> n >> c;

    vector<int> houses;

    for (int i = 0; i < n; i++) {
        cin >> t;
        houses.push_back(t);
    }

    // Binary Search 기반이므로 정렬 필수
    sort(houses.begin(), houses.end());

    // lo: 최솟값, hi: 최댓값
    int lo = 0, hi = INT_MAX, mid = 0;

    while (lo < hi) {
        // 조건을 만족하는 최댓값을 구할 때: mid = (lo + hi + 1) / 2
        // 조건을 만족하는 최솟값을 구할 때: mid = (lo + hi) / 2
        // 이해 안되면 외우면 됨
        mid = (lo + hi + 1) / 2;

        // 조건을 만족하면 lo = mid, 아님 hi = mid - 1
        // 이해 안되면 외우면 됨 2
        if (some_statement(10000)) {
            lo = mid;
        }
        else hi = mid - 1;
    }

    // 최종값
    cout << lo;
}
