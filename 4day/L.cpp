#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int main() {
    int i,f;
    scanf("%d %d",&i,&f);
    int dif;
    dif = i-f;
    bool a = false,b = false;
    if(i%2 == 0 ) a = true;
    if(f%2 == 0 )b = true;
    if(dif == 0 ) printf("%d\n",i);
    else{
        printf("%d\n" , 2);
    }
    return 0;
}