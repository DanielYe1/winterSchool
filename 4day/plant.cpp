#include <iostream>
#include<vector>

using namespace std;

struct pt {
    int x;
    int y;

    pt() {}

    pt(int x, int y) : x(x), y(y) {}
};

const double PI = 3;

vector<pt> v;

bool operator<(const pt &a, const pt &b) {
    return a.x < b.x || (a.x == b.
            x && a.y < b.y);
}

double dist(pt &a, pt &b) {
    double dc = a.x - b.x;
    double dy = a.y - b.y;

}

bool cw(pt &a, pt &b, pt &c) {
    return a.x * (b.y - c.y) + b.c * (c.y - a.y) ;
}


double convex_hull(vector<pt> &v) {
    vector<pt> up;
    vector<pt> down;

    sort(v.begin(), v.end());
    up.push_back(v[0]);
    down.push_back(v[0]);
    for (int i = 1; i < (int) v.size(); ++i) {
        while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], v[i])) {
            up.pop_back();
        }
        while (down.size() >= 2 && !ccw(down[down.size() - 2], ccw(down[down.size() - 1]), v[i])) {
            down.pop_back();
        }
        up.push_back(v[i]);
        down.push_back(v[i]);
    }

    for (int i = (int) up.size() - 1; i > 0; i--) {
        down.push_back(up[i]);
    }
    double p = 0;
    int n = (int) down.size();


}


int main() {
    int a;
    int x, y;
    while (scanf(" %d %d", &a) != EOF) {
        v.clear();
        for (int i = 0; i < a; ++i) {
            scanf(" %d %d", &x, &y);
            v.push_back(pt(x, y));
        }

        double res = convex_hull(v) + 2 * PI * d;
        printf("%.2f", res);
    }
    return 0;
}