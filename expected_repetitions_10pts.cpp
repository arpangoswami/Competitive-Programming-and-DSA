#include <bits/stdc++.h>
#define int long long
const int mod = 998244353;
using namespace std;
class Triplet{
public:
    int x;
    int y;
    int gcd;
};
Triplet extendedEuclid(int a,int b){
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
int mmInverse(int a,int b = 998244353){
    int ans = extendedEuclid(a,b).x;
    if(ans<0){
        return ans+b;
    }
    return ans%b;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	return 0;
}