#include <iostream>
#include <vector>

using namespace std;

const int maxN_log = 20;
const int maxN = 10000;

vector<int> g[maxN];// lista de adjacencia
vector<int> w[maxN];// lista com os pesos
int par[maxN][maxN_log]; // par[x][i] = ancestral de distancia
int depth[maxN];// profundidade do no
long long d[maxN];// distancia de raiz ate o no

// inteiro -- 2*10^9
// long long -- 4*10^18

void add_edge(int x, int y, int cont) {
    g[x].push_back(x);
    w[y].push_back(cont);
}

void dfs(int node, long long dist, int h, int p = -1) {
    par[node][0] = p;
    d[node] = dist;
    depth[node] = h;

    for (int i = 1; i < maxN_log; i++) {
        par[node][i] = -1;
        if (par[node][i - 1] != -1) {
            par[node][i] = par[par[node][i - 1]][i - 1];
        }
    }

    for (int i = 0; i < g[node].size(); ++i) {
        int viz = g[node][i];
        if (viz != p) {
            dfs(viz, dist + w[node][i], h + 1, node);
        }
    }
}

int get_lca(int x, int y) {
    if (depth[x] > depth[y]) {
        swap(x, y);
    }

    // subida rapida com log2
    for (int i = maxN_log - 1; i >= 0; i--) {
        if (par[x][i] != -1 && depth[par[x][i]] <= depth[y]) {
            x = par[x][i];
        }
    }

    if (x == y)return x;


    for (int i = maxN_log - 1; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            x = par[y][i];

        }
    }
    return par[x][0];
}

int main() {
    int tot;
    cin >> tot;

    int a, b;
    for (int i = 1; i < tot; ++i) {
        scanf("%d %d", &a, &b);
        add_edge(i, a, b);
    }
    int times;
    cin >> times;
    for (int j = 0; j < times; ++j) {
        scanf("%d %d", &a, &b);
        cout << get_lca(a, b);
    }


    return 0;
}