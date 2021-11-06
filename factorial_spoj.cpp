#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll zeros(ll n){
    ll num = 0;
    ll div = 5;
    while(true){
        num+=n/div;
        div*=5;
        if(n/div == 0){
            break;
        }
    }
    return num;
}
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        cout<<zeros(n)<<"\n";
    }
    return 0;
}
