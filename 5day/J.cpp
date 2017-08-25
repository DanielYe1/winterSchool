#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n,m,k,z;
    int dist = -1;
    scanf("%d %d %d",&n,&m,&k);

    for (int i = 1; i <n+1 ; i++) {
        scanf(" %d",&z);
        if(z!=0 && z<= k){
            if(dist == -1 )dist = abs(i-m);
            else dist = min(dist,abs(i-m));
        }
    }
    printf("%d\n",dist*10);
    return 0;
}