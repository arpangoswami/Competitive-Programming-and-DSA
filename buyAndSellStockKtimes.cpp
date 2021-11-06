#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){int n;
    cin>>n;
    vector<int> prices(n,0);
    for(int i=0;i<n;i++) cin>>prices[i];
    //int *peaks = new int[n]();
    //int idx = 0;
    int i = 0;//profit = 0;
        //if(n<=1) return 0;
    while(i<(n-1)){
        while(i<(n-1) && prices[i+1]<=prices[i]){
            i++;
        }
        if(i == (n-1)){
            break;
        }
        //profit-=prices[i];
        int buy = i;
        i++;
        while(i<n && prices[i]>=prices[i-1]){
            i++;
        }
        //profit+=prices[i-1];
        //peaks[idx++] = profit;
        //profit = 0;
        int sell = i-1;
        cout<<'('<<buy<<" "<<sell<<')'<<" ";
    }
    //sort(peaks,peaks+idx);
    //int maxProfit = 0;
    //for(int i=0;i<min(idx,k);i++){
      //  maxProfit+=peaks[i];
    //}
    //cout<<maxProfit<<endl;
    //delete []peaks;
    cout<<endl;}
}
