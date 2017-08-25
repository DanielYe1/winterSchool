#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int val[n];
    for (int k = 0; k < n; ++k) {
        scanf(" %d", &val[k]);
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (val[i] > val[j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}