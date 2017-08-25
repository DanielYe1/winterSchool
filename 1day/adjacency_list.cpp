#include <iostream>
#include <vector>

const int max = 10000;

using namespace std;

vector<int> g[max];
vector<int> m[max];

void add_edge(int x, int y, int cont) {
    g[x].push_back(x);
    m[y].push_back(cont);
}

int main() {


    return 0;
}