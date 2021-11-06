#include<bits/stdc++.h>
using namespace std;
int modExpRec(int a,int b,int c){
    if(a == 0){
        return 0;
    }
    if(b == 0){
        return 1;
    }
    long ans;
    if((b%2)==0){
        long smallAns = modExpRec(a,b/2,c);
        ans = ((smallAns%c) * (smallAns%c))%c;
    }
    else{
        long smallAns = modExpRec(a,b-1,c);
        ans = a%c;
        ans = ((ans*smallAns%c)%c);
    }
    return (int)((ans+c)%c);
}
int modExpIte(int a,int b,int c){
    long long ans = 1;
    while(b>0){
        int set_digit = b&1;
        if(set_digit){
            ans = ((ans%c) * (a%c))%c;
        }
        b>>=1;
        a = (a%c * a%c)%c;
    }

    return (int)((ans+c)%c);
}
int main(void){
    int a=2,b=10,c=5;
    cout<<modExpRec(2,10,5)<<endl;
    cout<<modExpIte(2312,3434,6789)<<endl;
}
