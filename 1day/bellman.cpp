#include <iostream>
#include <vector>

using namespace std;

const int INF = (int) 1e9;//ou 0x3f3f3f3f
const int maxN = 10000;

vector<int> g[maxN];// lista de adjacencia
vector<int> w[maxN];// lista com os pesos
long long d[maxN];// distancia de raiz ate o no

// inteiro -- 2*10^9
// long long -- 4*10^18

void bellman_ford(int s, int n) {
    for (int i = 0; i < n; i++) {
        d[i] = INF;
    }
    d[s] = 0;


    // it = numero de iteracoes
    // tempo O(VE)
    for (int it = 0; it < n; ++it) {
        for (int node = 0; node < n; ++node) {
            if (d[node] >= INF) {
                continue;
            }
            for (int i = 0; i < g[node].size(); ++i) {
                int viz = g[node][i];
                if (d[viz] > d[node] + w[node][i]) {
                    d[viz] = d[node] + w[node][i];
                }
            }
        }
    }

    for (int node = 0; node < n; node++) {
        if (d[node] > INF) {
            continue;
        }
        for (int i = 0; i < g[node].size(); i++) {
            int viz = g[node][i];
            if (d[viz] > d[node] + w[node][i]) {
                // reportar ciclo negativo
            }
        }
    }
}

int main() {

    return 0;
}