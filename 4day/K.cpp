#include <iostream>

using namespace std;

int main() {
    int times;

    cin >> times;

    for (int j = 0; j < times; ++j) {
        int n;
        cin >> n;


        int a[n];
        int aR[n];
        int b[n];
        int bR[n];

        for (int i = 0; i < n; ++i) {
            scanf(" %d", &a[i]);
            aR[n - i] = a[i];
        }

        for (int i = 0; i < n; ++i) {
            scanf(" %d", &b[i]);
            bR[n - i] = b[i];
        }

        int tempA = 0, tempB = 0, tempTot = 0, permTot = 0, tempAR = 0, tempBR = 0, tempTotR = 0;

        for (int i = 0; i < n; ++i) {
            tempA += a[i];
            tempB += b[i];

            tempAR += aR[i];
            tempBR += bR[i];

            if (tempA >= tempB) {
                tempTot++;
                if (permTot < tempTot) {
                    permTot = tempTot;
                }
            } else {
                tempTot = 0;
                tempA = 0;
                tempB = 0;
            }

            if (tempAR >= tempBR) {
                tempTotR++;
                if (permTot < tempTotR) {
                    permTot = tempTotR;
                }
            } else {
                tempTotR = 0;
                tempAR = 0;
                tempBR = 0;
            }
        }

        cout << permTot << endl;
    }

    return 0;
}