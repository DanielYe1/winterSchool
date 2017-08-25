#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = (int) 1e9;//ou 0x3f3f3f3f
const int maxN = 100;

vector<int> g[maxN];
int d[maxN];
int p[maxN];// parente

// source = s,
void bfs(int s, int n, int t) {
    queue<int> fila;
    for (int i = 0; i < n; i++) {
        d[i] = INF;
    }
    d[s] = 0;
    fila.push(s);

    while (!fila.empty()) {
        int next = fila.front();
        fila.pop();

        for (int i = 0; i < g[next].size(); ++i) {
            int viz = g[next][i];
            if (d[viz] > 1 + d[next]) {
                d[viz] = 1 + d[next];
                p[viz] = next;
                fila.push(viz);
            }
        }
    }

    vector<int> path;
    int aux = t;
    if (d[t] < INF) {
        while (aux != s) {
            path.push_back(aux);
            aux = p[aux];
        }
        path.push_back(s);
    }
    reverse(path.begin(), path.end());
}

int main() {

    return 0;
}