#include <iostream>
#include <unordered_set>

using namespace std;

int calculateMex(unordered_set<int> Set) {
    int Mex = 0;

    while (Set.find(Mex) != Set.end())
        Mex++;

    return (Mex);
}

int calculateGrundy(int n, int k) {
    for (int j = 1; j < k; j++) {
        if (j == k) {
            return k;
        }
    }

    unordered_set<int> Set; // A Hash Table

    for (int i = 1; i <= k; i++)
        Set.insert(calculateGrundy(n - i, k));

    return (calculateMex(Set));
}

int main() {

    int x, y;

    cin >> x >> y;

    cout << calculateGrundy(x, y);

    return 0;
}