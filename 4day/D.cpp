#include <iostream>
#include <algorithm>

using namespace std;


const int size = 4001;
int memo[size];

int higher = 0;

void sum(int init, int vals[], int qt, int final) {

    if (init == final) {
        higher = max(qt, higher);
        return;
    } else if (init > final) {
        return;
    }

    if (qt <= memo[init] && qt != 0) {
        return;
    }

    memo[init] = qt;

    sum(init + vals[0], vals, qt + 1, final);
    sum(init + vals[1], vals, qt + 1, final);
    sum(init + vals[2], vals, qt + 1, final);

    return;
}

int main() {

    int final;
    int vals[3];

    scanf("%d %d %d %d", &final, &vals[0], &vals[1], &vals[2]);

    sort(vals, vals + 3);

    sum(0, vals, 0, final);

    cout << higher << endl;

    return 0;
}