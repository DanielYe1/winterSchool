#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>

using namespace std;

int main() {
    vector<string> palavras;
    string s1,s2;
    cin >> s1 >> s2;
    s1 = s1+s2;
    sort(s1.begin(),s1.end());
    do{
        palavras.push_back(s1);
    }while(next_permutation(s1.begin(),s1.end()));
    for (int i = 0; i <s1.size() ; ++i) {
        palavras.size()
    }
}