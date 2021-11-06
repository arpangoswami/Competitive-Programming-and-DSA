#include<bits/stdc++.h>
using namespace std;
const int SIZE = 100000;
vector<int> dp(SIZE,0);
void maintain(){
    int i = 0;
    for(int i=0;i<SIZE;i++){
        int cards = (i+1)*2;
        cards += ((i+1)*(long)(i))/2 * 3;
        dp[i] = cards;
    }
}
void solve(){
    int n;
    cin>>n;
    if(n<dp[0]){
        cout<<0<<endl;
        return;
    }
    int py = 0;
    while(n>=dp[0]){
        int idx = lower_bound(dp.begin(),dp.end(),n) - dp.begin();
        if(dp[idx]> n){
            idx--;
            py++;
            n-=dp[idx];
        }
        else{
            py++;
            n = 0;
        }
        if(n<dp[0]){
            break;
        } 
    }
    cout<<py<<endl;
}
int main(){
    int test;
    cin>>test;
    maintain();
    while(test--){
        solve();
    }
    return 0;
}