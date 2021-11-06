#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
class Triplet{
public:
    long long x;
    long long y;
    long long gcd;
};
Triplet extendedEuclid(long long a,long long b){
    if(b == 0){
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    Triplet ans,smallAns = extendedEuclid(b,a%b);
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}
long long mmInverse(long long a,long long b = 998244353){
    long long ans = extendedEuclid(a,b).x;
    if(ans<0){
        return ans+mod;
    }
    return ans%mod;
}
long long modPower(long long a,long long b = 998244353){
    if(a == 0){
        return 0;
    }
    else if(b == 0){
        return 1;
    }
    long long ans;
    if(b%2 == 0){
        long long smallAns = modPower(a,b/2);
        ans = (smallAns%mod * smallAns%mod)%mod;
    }
    else{
        long long smallAns = modPower(a,b/2);
        ans = (a%mod * (smallAns%mod * smallAns%mod)%mod)%mod;
    }
    return ans;
}
int main(int argc,char const* argv[]){
    cout<<(2%mod*mmInverse(8)%mod)%mod<<endl;
    return 0;
}
