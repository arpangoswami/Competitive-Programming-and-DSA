#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> items;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,w;
        cin>>n>>w;
        items *arr = new items[n+1];
        for(int i=0;i<n;i++){
            cin>>arr[i].second;//value
        }
        for(int i=0;i<n;i++){
            cin>>arr[i].first;//weights
        }
        sort(arr,arr+n);
        int *dp = new int[w+1]();
        for(int i=1;i<=w;i++){
            for(int j=0;j<n;j++){
                if(arr[j].first>i){
                    break;
                }
                else
                    dp[i] = max(dp[i],dp[i-arr[j].first]+arr[j].second);//maximum of already present there or maximum taking a value
            }
        }
        cout<<dp[w]<<endl;
        delete []dp;
        delete []arr;
    }
}
