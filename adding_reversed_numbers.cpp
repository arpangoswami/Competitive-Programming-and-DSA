#include<bits/stdc++.h>
using namespace std;
long rev(long num){
    long revers = 0;
    while(num!=0){
        int temp = num%10;
        revers = (revers*10)+temp;
        num/=10;
    }
    return revers;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        long a,b;
        cin>>a>>b;
        a = rev(a);
        b = rev(b);
        cout<<rev(a+b)<<endl;
    }
}
