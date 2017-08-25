#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int qtP;
    int count = 0;

    int aBroken = 0;

    for (int i = 0; i < n; ++i) {
        cin >> qtP;
        if (qtP == 1) {
            if (a > 0) {
                a--;
            } else if (b > 0) {
                b--;
                aBroken++;;
            } else if (aBroken > 0) {
                aBroken--;
            } else {
                count++;
            }
        } else if (qtP == 2) {
            if (b > 0) {
                b--;
            } else {
                count += 2;
            }
        }
    }

    cout << count << endl;


    return 0;
}