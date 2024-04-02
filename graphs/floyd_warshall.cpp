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

// adj matrix
int adj[5][5] = {
    {0, 5, 0, 9, 1},
    {5, 0, 2, 0, 0},
    {0, 2, 0, 7, 0},
    {9, 0, 7, 0, 2},
    {1, 0, 0, 2, 0}
};

int dist[5][5] = {0};

// distance matrix 생성
void create_dist_mat() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) dist[i][j] = 0;
            else if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = INF;
        }
    }
}

// Floyd-Warshall 알고리즘
void find_shortest_path() {
    // k: 중간 노드, i: 시작 노드, j: 종착 노드
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                // 자신과 (시작 -> 중간 -> 종착의 거리) 를 비교
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    create_dist_mat();
    find_shortest_path();

    // from node(2) to node(4)
    cout << dist[2][4];
}