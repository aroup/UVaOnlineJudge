#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int t;
    long long int x, k, a, b, p, q;
    while(scanf("%d", &t) == 1){
        while(t--){
            scanf("%lld%lld", &x, &k);
            a = floor((double)x/k);
            b = ceil((double)x/k);
            for(p = 0; p*a <= x; p++)
                if((x-p*a)%b == 0)   {q = (x-p*a)/b;   break;}
            printf("%lld %lld\n", p, q);
        }
    }
    return 0;
}
