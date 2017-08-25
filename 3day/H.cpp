#include <iostream>

using namespace std;

int main() {

    int nDoc;
    int nPage;
    cin >> nDoc >> nPage;
    while (nDoc != 0 && nPage != 0) {

        int qtLetra = nDoc / nPage;
        if (nDoc % nPage > 0) {
            qtLetra++;
        }
        int oQt = qtLetra - 4;
        if (qtLetra < 6) {
            cout << "Poodle" << endl;
            cin >> nDoc >> nPage;
            continue;
        }
        if (qtLetra >= 20) {
            oQt = 16;
        }
        cout << "P";
        for (int i = 0; i < oQt; i++) {
            cout << "o";
        }
        cout << "dle\n";
        cin >> nDoc >> nPage;
    }

    return 0;
}