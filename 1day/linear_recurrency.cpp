#include <iostream>

using namespace std;

// achar base^p % mod
long long int fast_exp(long long base, int p, int mod) {
    if (p == 0) {
        return 1 % mod;
    }

    long long a = fast_exp(base, p / 2, mod);
    if (p & 1) {
        return ((a * a) % mod * base) % mod;
    } else {
        return (a * a) % mod;
    }
}

// mesma lógica que calculo da questão de formigas
long long int fast_exp2(long long base, int p, int mod) {
    long long res = 0;
    while (p > 0) {
        if (p & 1) {
            res = res * base;
            res %= mod;
        }
        base = (base * base) % mod;
        p /= 2;
    }
    return res;
}

long long mod = (int) 1e9 + 7;
// se mod = 10^9 + 7
const int maxN = 100000;
long long mat[maxN][maxN];
long long res[maxN][maxN];
long long aux[maxN][maxN];

void mul(long long a[maxN][maxN], long long b[maxN][maxN], long long c[maxN][maxN], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            aux[i][j] = 0;
        }
    }

    // com n^3
    long long mod2 = 1LL * mod * mod; // gambiarra de tentar diminuir quantidade linear da conta
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                aux[i][j] += b[i][k] * c[k][j];
                if (aux[i][j] >= mod2) {
                    aux[i][j] -= mod2;
                }
            }
        }
    }

    // com n^2
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = aux[i][j] % mod;
        }
    }

}

fast_exp_mat(int p, int n) {
    for (int i = 0; i < maxN; ++i) {
        for (int j = 0; j < maxN; ++j) {
            res[i][j] = 0;
        }
        res[i][i] = 1;
    }

    while (p > 0) {
        if (p & 1) {
            mul(res, res, mat, maxN);
        }

    }
}


int main() {

    return 0;
}