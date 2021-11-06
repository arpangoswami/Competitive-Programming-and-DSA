#include<bits/stdc++.h>
using namespace std;
long gcd(long a,long b){
    if(a<b){
        return gcd(b,a);
    }
    if(b==0){
        return a;
    }
    return gcd(a%b,b);
}
int main(void){
    long x,y,p,q;
    cin>>x>>y>>p>>q;
    int b1,b2,b3;
    long lcmXP = (x*p)/gcd(x,p);
    b1 = lcmXP/x;
    b3 = lcmXP/p;
    long lcm2 = (y*(b3*q))/gcd(y,(b3*q));
    b2 = lcm2/y;
    long m = lcm2/(b3*q);
    b3*=m;
    b1*=m;
    long a = gcd(b1,gcd(b2,b3));
    b1/=a;
    b2/=a;
    b3/=a;
    cout<<b1<<" "<<b2<<" "<<b3<<endl;
}
