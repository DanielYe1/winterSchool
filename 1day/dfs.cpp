#include <iostream>

using namespace std;

const int timer = 0;
int color[10];

void dfs(int node) {
    color[node] = 1;

}

const int max_log = 20;
const int size = 100000;
int par[size][size];
int depth[size];


void dfsAnt(int node, int h, int p) {
    par[node][0] = p;
    depth[node] = h;

    for (int i = 0; i < max_log; ++i) {
        par[node][i] = -1;
        if (par[node][i - 1] != -1) {
            par[node][i] = par[par[node][i - 1]][i - 1];
        }
    }

    for (int j = 0; j <; ++j) {
        if (viz != p) {
            dfsAnt(viz, h + w[node][j], node);
        }
    }
}

int main() {

    return 0;
}