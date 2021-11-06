#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i=2;i<=(n-1);i++){
        ans += i * (i+1);
    }
    cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin>>test;
    while(test--){
        solveQuestion();
    }
    return 0;
}