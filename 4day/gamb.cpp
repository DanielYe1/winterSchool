#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int times;

    cin >> times;

    for (int j = 0; j < times; ++j) {
        int n;
        cin >> n;


        int a[n];

        for (int i = 0; i < n; ++i) {
            scanf(" %d", &a[i]);
        }

        int tmp;
        for (int i = 0; i < n; ++i) {
            scanf(" %d", &tmp);
            a[i] -= tmp;
        }


        sort(a, a + n);

        int temp = 0, permTot = 0;

        for (int i = n - 1; i >= 0; i--) {
            temp += a[i];
            if (temp >= 0) {
                permTot++;
            } else {
                break;
            }
        }

        cout << permTot << endl;
    }

    return 0;
}