//
// Created by Garvit Sharma on 10/06/18.
//

#include <bits/stdc++.h>

#define MAXN 10005

using namespace std;

int data[MAXN];

int main()
{
    int t,n,a,b,na,nb;
    double p;
    scanf("%d",&t);
    while(t--) {
        na=0,nb=0;
        scanf("%d %d %d",&n,&a,&b);
        for(int i=0;i<n;i++){
            scanf("%d",&data[i]);
            if (data[i]==a) {
                na++;
            } if (data[i]==b) {
                nb++;
            }
        }
        //cout << na << " " << nb << endl;
        p=((na/(n*1.0)) * (nb/(n*1.0)));
        printf("%.10f\n", p);
        //cout << p << endl;
    }
    return 0;
}