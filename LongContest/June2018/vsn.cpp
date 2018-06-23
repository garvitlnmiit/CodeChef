//
// Created by Garvit Sharma on 10/06/18.
//

#include<bits/stdc++.h>
#define LL long long

using namespace std;
typedef vector< long long int> V;

V subtract(V a,V b){
    V ans;
    for(int i=0;i<3;++i){
        ans.push_back(a[i]-b[i]);

    }
    return ans;
}

LL dot(V a,V b){
    LL ans=0;
    for(int i=0;i<3;++i){
        ans+=a[i]*b[i];
    }
    return ans;
}
V input(){
    LL x;
    V a;
    for(int i=0;i<3;i++){
        cin>>x;
        a.push_back(x);
    }
    return a;


}
int main(){
    LL t;
    scanf("%d",&t);

    while(t--){
        V p,q,d,c;
        LL rad;
        LL c1,c2,c3,c4,c5,c6;
        V cp,qp;
        p=input();
        q=input();
        d=input();
        c=input();
        cin>>rad;



        cp=subtract(c,p);
        qp=subtract(q,p);

        c1=dot(cp,cp);
        c2=dot(cp,qp);
        c3=dot(cp,d);
        c4=dot(qp,qp);
        c5=dot(qp,d);
        c6=dot(d,d);

        long double X,Y,Z;

        X=(rad*rad*c6-(c1*c6)+(c3*c3));
        Y=2*(rad*rad*c5-(c5*c1)+(c2*c3));
        Z=(rad*rad*c4-(c1*c4)+(c2*c2));




        long double t,t1,t2;

        if(X==0){
            t=(-1*Z)/Y;
            printf("%.10Lf\n", t);
        }
        else{
            t1=((-1*Y)+sqrt(Y*Y-(4*X*Z)))/(2*X);
            t2=((-1*Y)-sqrt(Y*Y-(4*X*Z)))/(2*X);

//            if (t1<=t2 && t1>=0.0) printf("%.10Lf\n", t1);
//            else if (t2<t1 && t2>=0.0) printf("%.10Lf\n", t2);
            if(t1>=0.0 && t2<0.0)printf("%.10Lf\n", t1);
            else if(t1<0.0 && t2>=0.0)printf("%.10Lf\n", t2);
            else if(t1>=0.0 && t2>=0.0)printf("%.10Lf\n", min(t1,t2));
        }
    }

    return 0;
}