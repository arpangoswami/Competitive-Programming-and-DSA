#include<bits/stdc++.h>
using namespace std;
int costMin(int *arr,int n){
    int changeCost = 0;
    map<int,int> cyclicFreq;
    for(int i=0;i<n;i++){
        if(arr[i]>n){
            changeCost++;
        }
        else{
            if(arr[i]>(i+1)){
                int shift = (i+1+n)-arr[i];
                cyclicFreq[shift]++;
            }
            else if(arr[i]<=(i+1)){
                int shift = (i+1)-arr[i];
                cyclicFreq[shift]++;
            }
        }
    }
    map<int,int> costs;
    for(auto it = cyclicFreq.begin();it!=cyclicFreq.end();it++){
        int cost1 = (it->first) + (n-(it->second));
        costs[it->first] = cost1;
    }
    int minCost = n,shift = 0;
    for(auto it = costs.begin();it!=costs.end();it++){
        if(minCost>it->second){
            minCost = it->second;
            shift = it->first;
        }
        if(minCost< it->first){
            break;
        }
    }
    return minCost;
}
int main(int argc,char const *argv[]){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int q;
    cin>>q;
    while(q--){
        int idx,num;
        cin>>idx>>num;
        arr[idx-1] = num;
        cout<<costMin(arr,n)<<endl;
    }
    delete []arr;
    return 0;
}
