#include<bits/stdc++.h>
using namespace std;
struct disk{
    long radius;
    long height;
};
bool sorting(const disk &d1,const disk &d2){
    if(d1.radius>d2.radius){
        return true;
    }
    else if(d1.radius<d2.radius){
        return false;
    }
    else{
        if(d1.height>d2.height){
            return true;
        }
    }
    return false;
}
long maximumHeight(disk *arr,int idx,int n,long ht,long r){
    if(idx==n){
        return 0;
    }
    if(ht>arr[idx].height && r>arr[idx].radius){
        return max(maximumHeight(arr,idx+1,n,arr[idx].height,arr[idx].radius)+arr[idx].height,maximumHeight(arr,idx+1,n,ht,r));
    }
    return maximumHeight(arr,idx+1,n,ht,r);
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        disk *arr = new disk[n];
        for(int i = 0;i < n;i++){
            cin>>arr[i].radius>>arr[i].height;
        }
        sort(arr,arr+n,sorting);
        cout<<maximumHeight(arr,0,n,INT_MAX,INT_MAX)<<endl;
        delete []arr;
    }
}
