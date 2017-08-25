#include <iostream>

using namespace std;

const int max = 10000;

int mat[max][max];

void add_edge(int x, int y, int cont) {
    mat[x][y] = cont;
}