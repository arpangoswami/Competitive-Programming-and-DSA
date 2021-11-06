#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int check(int a,int b,int c){
    int upper=c;
    int lower=2;
    bool flag=false;
    while(lower<=upper){
        int mid=lower+(upper-lower)/2;
        if((mid-1)>(b*b)/(a-1) && (mid-2)<=(b*b)/(a-1)){
            flag=true;
            return mid;
        }
        else if((mid-1)>(b*b)/(a-1) && (mid-2)>(b*b)/(a-1)){
            upper=mid-1;
        }
        else if((mid-1)<=(b*b)/(a-1)){
            lower=mid+1;
        }
    }
    if(flag==false)
        return -1;
}
int main(void){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        int num=0;
        cin>>a>>b>>c;
        for(int i=1;i<=b;i++){
            if(i*i>=(a-1)*(c-1))
                    break;
            for(int j=2;j<=a;j++){
                int k=check(j,i,c);
                if(k!=-1)
                    num=(num%mod+(c-k+1)%mod)%mod;
            }
        }
        cout<<num%mod<<endl;
    }
}
