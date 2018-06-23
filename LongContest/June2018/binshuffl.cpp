//
// Created by Garvit Sharma on 10/06/18.
//

#include <bits/stdc++.h>
#define LL long long

using namespace std;

int getOnes(LL num)
{
    int cnt=0;
    while(num>0) {
        cnt+=(num%2);
        num/=2;
    }
    return cnt;
}

int main()
{
    int t;
    LL a,b;

    scanf("%d",&t);

    while (t--) {
        scanf("%lld %lld",&a,&b);
        if (a==b) {
            printf("0\n");
        } else if (a>0 && b<=1) {
            printf("-1\n");
        } else {
            int ops = getOnes(b - 1) - getOnes(a) + 1;
            printf("%d\n", ops > 0 ? ops : 2);
        }
    }

    return 0;
}