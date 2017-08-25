#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int nBac, nCon;
    cin >> nBac >> nCon;

    int mat[nBac][2];
    int lixo, lixo2;
    for (int i = 0; i < nBac; ++i) {
        scanf("%d %d %d %d", &mat[i][0], &lixo, &mat[i][1], &lixo2);
        if (mat[i][0] > mat[i][1]) {
            int aux = mat[i][0];
            mat[i][0] = mat[i][1];
            mat[i][1] = aux;
        }
    }

    int lIn, lOut, qt;

    for (int k = 0; k < nCon; ++k) {
        scanf("%d %d", &lIn, &lOut);
        qt = 0;
        for (int i = 0; i < nBac; ++i) {
            if (mat[i][0] < lIn) qt += 1;
            if (mat[i][1] > lOut) qt += 1;
        }
        cout << qt << endl;
    }


    return 0;
}