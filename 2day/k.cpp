#include <iostream>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f
const int maxN = 105;

char mat[maxN][maxN];
int d1[maxN][maxN];
int d2[maxN][maxN];

queue<pair<int, int>> fila;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int is_in(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void pintaBaratas(int maxX, int maxY) {
    int x, y;
    int nx, ny;
    while (!fila.empty()) {
        x = fila.front().first;
        y = fila.front().second;
        fila.pop();

        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (is_in(nx, ny, maxX, maxY)) {
                if (mat[nx][ny] != '#' && d1[nx][ny] > 1 + d1[x][y]) {
                    d1[nx][ny] = 1 + d1[x][y];
                    fila.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void bfsPessoa(int cX, int cY, int maxX, int maxY) {
    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            d2[i][j] = INF;
        }
    }
    d2[cX][cY] = 0;
    int x, y;
    int nx, ny;
    fila.push(make_pair(cX, cY));
    while (!fila.empty()) {
        x = fila.front().first;
        y = fila.front().second;
        fila.pop();

        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (is_in(nx, ny, maxX, maxY)) {
                if (mat[nx][ny] != '#' && d2[nx][ny] > 1 + d2[x][y]) {
                    d2[nx][ny] = 1 + d2[x][y];
                    fila.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {

    int times;

    cin >> times;

    for (int k = 0; k < times; ++k) {

        int x, y;
        cin >> x >> y;

        char value;
        int xInit, yInit;
        int xFinal, yFinal;

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                d1[i][j] = INF;
            }
        }

        for (int i = 0; i < x; ++i) {
            scanf(" %s", mat[i]);
            for (int j = 0; j < y; ++j) {
                value = mat[i][j];
                if (value == '*') {
                    d1[i][j] = 0;
                    fila.push(make_pair(i, j));
                } else if (value == 'X') {
                    xFinal = i;
                    yFinal = j;
                } else if (value == 'S') {
                    xInit = i;
                    yInit = j;
                }
            }
        }

        pintaBaratas(x, y);
        bfsPessoa(xInit, yInit, x, y);

        if (d1[xFinal][yFinal] <= d2[xFinal][yFinal]) {
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
        }
    }
    return 0;
}