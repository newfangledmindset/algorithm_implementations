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

// distance matrix 생성
void create_rand_dist_mat(vector<vi> &dist, const int &n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> ds(-20, 20);

    int w;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            w = ds(gen);
            if (i == j) dist[i][j] = 0;
            else if (w > 0) dist[i][j] = w;
            else dist[i][j] = INF;
        }
    }
}

// Floyd-Warshall 알고리즘
void find_shortest_path(vector<vi> &dist, vector<vi> &path, const int &n) {
    // k: 중간 노드, i: 시작 노드, j: 종착 노드
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 자신과 (시작 -> 중간 -> 종착의 거리) 를 비교
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    // 경로 저장
                    path[i][j] = k;
                }
            }
        }
    }
}

// 경로 출력
void print_path(const vector<vi> &path, const int &s, const int &t) {
    if (path[s][t] != 0) {
        print_path(path, s, path[s][t]);
        cout << path[s][t] << ' ';
        print_path(path, path[s][t], t);
    }
}

// 출발, 도착점도 포함하여 출력
void print_c_path(const vector<vi> &path, const int &s, const int &t) {
    cout << s << ' ';
    print_path(path, s, t);
    cout << t << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 4, s, t;

    for (int i = 1; i <= 10; i++) {
        vector<vi> adj(n, vi(n, 0));
        vector<vi> dist(n, vi(n, 0));
        vector<vi> path(n, vi(n, 0));

        create_rand_dist_mat(dist, n);

        auto begin = chrono::steady_clock::now();
        cout << "Case #" << i << '\n';
        cout << "Size of a matrix: " << n << '\n';
        find_shortest_path(dist, path, n);

        cout << "Shortest distance: ";
        if (dist[1][n - 1] >= INF) cout << "INF" << '\n';
        else cout << dist[1][n - 1] << '\n';
        
        cout << "Path: ";
        print_c_path(path, 1, n - 1);

        auto end = chrono::steady_clock::now();

        cout << '\n';
        cout << "Elapsed time: " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "ms" << '\n' << endl;

        n *= 2;
    }
}