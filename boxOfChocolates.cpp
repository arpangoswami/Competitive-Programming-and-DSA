#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int *arr = new int[n];
        int maxi = 1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            maxi = max(maxi,arr[i]);
        }
        unordered_set<int> indices;
        for(int i=0;i<n;i++){
            if(arr[i]==maxi){
                indices.insert(i);
            }
        }
        if(indices.size()==1){
            cout<<n/2<<endl;
            continue;
        }
        int minIdx = INT_MAX,maxIdx = INT_MIN;
        for(auto it = indices.begin();it!=indices.end();it++){
            minIdx = min(minIdx,*it);
            maxIdx = max(maxIdx,*it);
        }
        if((maxIdx-minIdx)<=(n/2)){
            cout<<(n/2)-(maxIdx-minIdx)<<endl;
        }
        else{
            cout<<0<<endl;
        }
        delete []arr;
    }
}
