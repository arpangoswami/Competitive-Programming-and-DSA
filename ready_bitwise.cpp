#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
class Triplet{
public:
    int x;
    int y;
    int gcd;
};
Triplet extendedEuclid(long a,long b){
    if(b == 0){
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    //if(a<b) return extendedEuclid(b,a);
    Triplet ans,smallAns = extendedEuclid(b,a%b);
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}
int mmInverse(int a,int b = 998244353){
    long ans = extendedEuclid(a,b).x;
    if(ans<0){
        return ans+b;
    }
    return ans;
}
int32_t main(void){
    cout<<3 * mmInverse(16)<<endl;
    cout<<(3%mod * mmInverse(16)*mod)%mod<<endl;
}
