#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int sum = 0,*arr = new int[n];
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        bool *dp = new bool[sum+1]();
        dp[arr[0]] = true;
        dp[0] = true;
        for(int i = 1;i<n;i++){
            for(int j=sum;j>=arr[i];j--){
                if(dp[j-arr[i]]==true){
                    dp[j] = true;
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<=sum;i++){
            if(dp[i] == true){
                cnt++;
            }
        }
        cout<<cnt<<endl;
        delete []dp;
        delete []arr;
    }
}
