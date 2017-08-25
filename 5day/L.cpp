#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main() {

    int cupNumbers, qtHoles, qtMoves;
    cin >> cupNumbers >> qtHoles >> qtMoves;

    int bone = 1;
    int holes[qtHoles];

    for (int i = 0; i < qtHoles; ++i) {
        scanf(" %d", &holes[i]);
    }

    sort(holes, holes + qtHoles);


    int a[qtMoves], b[qtMoves];

    for (int l = 0; l < qtMoves; ++l) {
        scanf(" %d %d", &a[l], &b[l]);
    }
    if (binarySearch(holes, 0, qtHoles, bone) != -1) {
        cout << bone << endl;
        return 0;
    }

    for (int l = 0; l < qtMoves; ++l) {
        if (bone == a[l]) {
            bone = b[l];
            if (binarySearch(holes, 0, qtHoles, bone) != -1) {
                break;
            }
        } else if (bone == b[l]) {
            bone = a[l];
            if (binarySearch(holes, 0, qtHoles, bone) != -1) {
                break;
            }
        }

    }

    cout << bone << endl;

    return 0;
}