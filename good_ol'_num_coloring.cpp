#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b>a)
        return gcd(b,a);
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int a,b;
        cin>>a>>b;
        int hcf = gcd(a,b);
        if(hcf == 1){
            cout<<"Finite"<<endl;
        }
        else{
            cout<<"Infinite"<<endl;
        }
    }
}
