#include <iostream>
#include <vector>
#include <queue>

using namespace std;


const int maxN = 100000;
vector<int> g[maxN];
vector<int> w[maxN];
int d[maxN];
int p[maxN];

void dijkstra(int s, int n) {
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i) {
        d[i] = INF;
    }
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        int next = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (d[next] < cost) continue;

        for (int i = 0; i < g[next].size(); ++i) {
            int viz = g[next][i];
            if (d[viz] > w[next][i] + d[next]) {
                d[viz] = d[next] + w[next][i];
                p[viz] = next;
                pq.push(make_pair(-d[viz], viz));
            }
        }
    }
}

int main() {

    return 0;
}