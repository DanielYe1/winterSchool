#include <iostream>

using namespace std;

int const size = 1001;

bool isValid(int x, int y) {
    return 0 <= x && x <= 1000 && y >= 0 && y <= 1000;
}

bool clean(int x, int y, int field[size][size]) {
    if (field[x][y] == 0) {
        return false;
    }

    field[x][y] = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (isValid(x + i, y + j)) {

                if (field[x + i][y + j] == 1) {
                    clean(x + i, y + j, field);
                }
            }
        }
    }
    return true;
}


int main() {
    int times;
    cin >> times;

    for (int k = 1; k <= times; ++k) {


        int field[size][size];
        int mobs;
        int tot = 0;
        cin >> mobs;

        int xCord, yCord;

        int xP[mobs];
        int yP[mobs];

        for (int i = 0; i < mobs; ++i) {
            cin >> xCord >> yCord;
            field[xCord][yCord] = 1;
            xP[i] = xCord;
            yP[i] = yCord;
        }

        for (int j = 0; j < mobs; ++j) {
            if (clean(xP[j], yP[j], field)) {
                tot++;
            }
        }

        printf("Case %d: %d\n", k, tot);
    }

    return 0;
}

