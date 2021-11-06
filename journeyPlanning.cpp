#include<bits/stdc++.h>
using namespace std;
struct city{
    long long idx;
    long long beauty;
    long long diff;
};
bool compare(city &a,city &b){
    return a.diff<b.diff;
}
int main(void){
    long long n;
    cin>>n;
    city *arr1 = new city[n];
    for(long long i=0;i<n;i++){
        cin>>arr1[i].beauty;
        arr1[i].idx = i;
        arr1[i].diff = arr1[i].beauty - arr1[i].idx;
    }
    sort(arr1,arr1+n,compare);
    if(n>0){
    long long sum = arr1[0].beauty,max_sum = arr1[0].beauty;
    for(long long i=1;i<n;i++){
        if(arr1[i].diff!=arr1[i-1].diff){
            sum = (long long)arr1[i].beauty;
            max_sum = max(max_sum,sum);
        }
        else{
            sum+=(long long)arr1[i].beauty;
            max_sum = max(max_sum,sum);
        }
    }
    cout<<max_sum<<endl;
    }
    else{
        cout<<0<<endl;
    }
    delete []arr1;
}
