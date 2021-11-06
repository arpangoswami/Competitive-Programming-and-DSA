#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Triplet{
public:
    ll x;
    ll y;
    ll gcd;
};
Triplet extendedEuclid(ll a,ll b){
    if(b==0){
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
        Triplet smallAns = extendedEuclid(b,a%b);
        Triplet ans;
        ans.x = smallAns.y;
        ans.y = smallAns.x - (a/b)*smallAns.y;
        ans.gcd = smallAns.gcd;
        return ans;
}
ll moduloinverse(ll A,ll M){
    ll ans = extendedEuclid(A,M).x;
    return (ans%M+M)%M;
}

int main(void){
    int test;
    cin>>test;
    while(test--){
        ll a,b,d;
        cin>>a>>b>>d;
        ll g = __gcd(a,b);
        if(d%g){
            cout<<0<<endl;
            continue;
        }
        if(d==0){
            cout<<1<<endl;
            continue;
        }
            a/=g;
            b/=g;
            d/=g;
            ll y1 = ((d%a)*moduloinverse(b,a))%a;
            ll firstvalue = (d/b);
            if(d<b*y1){
                cout<<0<<endl;
                continue;
            }
            ll n = (firstvalue - y1)/a;
            cout<<(n+1)<<endl;

    }
}
