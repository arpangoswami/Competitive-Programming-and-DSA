#include<bits/stdc++.h>
long long const mod = 1e9+7;
using namespace std;
long long power(long long a,long long b){
    if(b == 0){
        return 1;
    }
    if(a == 0){
        return 0;
    }
    long long ans1 = power(a,b/2);
    long long bigAns = ((ans1%mod) * (ans1%mod))%mod;
    if(b%2 == 1){
        return (bigAns%mod * a%mod)%mod;
    }
    return bigAns;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test;
    cin>>test;
    while(test--){
        long long n,a;
        cin>>n>>a;
        long long ans = 0;
        for(long long i=1;i<=n;i++){
            ans = (ans%mod + power(a,2*i-1)%mod)%mod;
            long long temp = power(a,2*i-1);
            a = (a%mod * temp%mod)%mod;
        }
        cout<<ans%mod<<"\n";
    }
    return 0;
}
