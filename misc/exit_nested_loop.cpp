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

    // Lambda function을 이용한 nested loop 탈출
    auto loop = []
    {
        for (int i = 0; i < 10; i++) {
            while (true) {
                while (true) {
                    while (true) {
                        // exit
                        return;
                    }
                }
            }
        }
    };

    loop();

    cout << 1;
}