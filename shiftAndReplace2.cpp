#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
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
    int minCost = n,minShift = 0;
    for(int i=0;i<(n-1);i++){
        if(cyclicFreq.count(i)){

        }
    }

    for(auto it = costs.begin();it!=costs.end();it++){
        if(minCost>it->second){
            minCost = it->second;
            minShift = it->first;
        }
        if(minCost< it->first){
            break;
        }
    }
    for(int i=0;i<n-1;i++){
        if(costs.count(i) == 0){
            costs[i] = n;
        }
    }
    //cout<<"min cost is "<<minCost<<endl;
    int q;
    cin>>q;
    int ct = 0;
    while(q--){
        int idx,num;
        cin>>idx>>num;
        int shift;
        arr[idx-1] = num;
        bool flag = false;
        if(arr[idx-1]>n){
            flag = true;
            ct++;
        }
        else{
            if(arr[idx-1]>(idx)){
                shift = (idx+n)-arr[idx-1];
            }
            else if(arr[idx-1]<=(idx)){
                shift = (idx)-arr[idx-1];
            }
        }
        //cout<<shift<<" shift "<<endl;
        if(shift == minShift && !flag){
            minCost--;
            costs[shift]--;
            cout<<minCost+ct<<endl;
        }
        else if(shift!=minShift && !flag){
            //cout<<" yoo "<<costs[shift]<<endl;
            costs[shift]--;
            costs[minShift]++;
            if(costs[shift] < costs[minShift]){
                minCost = costs[shift]+ct;
                minShift = shift;
            }
            cout<<minCost<<endl;
        }
        else if(flag){
            //cout<<" yolo "<<endl;
            cout<<(minCost+ct)<<endl;
        }
    }
    delete []arr;
    return 0;
}
