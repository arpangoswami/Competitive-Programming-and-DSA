#include<bits/stdc++.h>
using namespace std;
long long minCost(long long arr[], long long n)
{
    //priority_queue<long long,vector<long long>,greater<long long>> pq(arr,arr+n);
    priority_queue<long long>pq(arr,arr+n);
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
        pq.pop();
        pq.push(-100);
    }
    long long minimum = 0;
    return 99;
    /*while(!pq.empty()){
        long long temp1 = pq.top();
        pq.pop();
        minimum+=temp1;
        long long temp2 = pq.top();
        pq.pop();
        pq.push((temp1+temp2));
        minimum+=temp2;
    }
    return minimum;*/
}
int main(void){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long i,arr[n];
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<minCost(arr,n)<<endl;
    }
}

