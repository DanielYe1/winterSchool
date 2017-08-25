#include <iostream>

using namespace std;

int sum(int x, int k[], int n, int max) {
    if (x == max) {
        return 1;
    } else if (x > max) {
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (sum(x + k[i], k, n, max)) {
            return 1;
        }
    }
    return 0;
}

int main() {

    int n, val;
    cin >> n >> val;
    val = (int) abs(val);

    int k[n];

    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }

    if (sum(0, k, n, val)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}