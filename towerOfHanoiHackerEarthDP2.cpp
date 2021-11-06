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
        long *ht = new long[n](),maxi = 0;
        ht[0] = arr[0].height;
        for(int i=1;i<n;i++){
            ht[i] = arr[i].height;
            for(int j=0;j<i;j++){
                if(arr[j].height>arr[i].height && arr[j].radius>arr[i].radius){
                    ht[i] = max((ht[j]+arr[i].height),(ht[i]));
                }
            }
            maxi = max(ht[i],maxi);
        }
        cout<<maxi<<endl;
        delete []ht;
        delete []arr;
    }
}
