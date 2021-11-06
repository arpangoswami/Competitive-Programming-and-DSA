#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxm = 2e6;
vector<int> arr(maxm);
vector<int> arr2(maxm);
void solveQuestion(){
    int n;
    cin >> n;
    int ans = 0;
    int idx = lower_bound(arr.begin(),arr.end(),n) - arr.begin();
    if(arr[idx] == n){
        ans += (idx * (idx+1))/2;
    }else{
        idx--;
        int addition = (idx * (idx+1))/2;
        ans += addition;
        auto id2 = lower_bound(arr2.begin(),arr2.end(),n-arr[idx]) - arr2.begin();
        ans += id2;
    } 
    cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin>>test;
    arr[0] = 0;
    arr2[0] = 0;
    for(int i=1;i<maxm;i++){
        arr[i] = (i*(i+1))/2;
        arr2[i] = arr[i];
        arr[i] += arr[i-1];
    }
    while(test--){
        solveQuestion();
    }
    return 0;
}