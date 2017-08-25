#include <iostream>

using namespace std;

int main() {

    int lado;
    cin >> lado;

    int sizes[lado];
    scanf(" %d", &sizes[0]);
    int igual = true;
    int higher = sizes[0];
    for (int i = 1; i < lado; ++i) {
        scanf(" %d", &sizes[i]);
        if (sizes[0] != sizes[i]) {
            igual = false;
        }
        if (sizes[i] > higher) {
            higher = sizes[i];
        }
    }

    if (igual) {
        cout << 0 << endl;
    }

    int temp = 0;
    int count = 0;
    for (int j = 0; j < lado; ++j) {
        if (lado < higher) {
            temp += lado;
            count++;
        } else {

        }
    }


    return 0;
}