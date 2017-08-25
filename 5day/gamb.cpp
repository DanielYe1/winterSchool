#include <iostream>
#include <algorithm>

using namespace std;

bool find(int arr[], int l, int x) {
    for (int i = 0; i < l; ++i) {
        if (arr[i] == x) {
            return true;
        }
    }
    return false;
}

int main() {

    int cupNumbers, qtHoles, qtMoves;
    cin >> cupNumbers >> qtHoles >> qtMoves;

    int bone = 1;
    int holes[qtHoles];
    sort(holes, holes + qtHoles);

    for (int i = 0; i < qtHoles; ++i) {
        scanf(" %d", &holes[i]);
    }

    int a[qtMoves], b[qtMoves];

    for (int l = 0; l < qtMoves; ++l) {
        scanf(" %d %d", &a[l], &b[l]);
    }
    for (int l = 0; l < qtMoves; ++l) {
        if (bone == a[l]) {
            bone = b[l];
            if (find(holes, qtHoles, bone)) {
                break;
            }
        } else if (bone == b[l]) {
            bone = a[l];
            if (find(holes, qtHoles, bone)) {
                break;
            }
        }

    }

    cout << bone << endl;

    return 0;
}