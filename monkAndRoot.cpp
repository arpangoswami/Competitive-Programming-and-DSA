#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]){
    long n,k;
    cin>>n>>k;
    long *arr = new long[n];
    long s = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s+=arr[i];
    }
    priority_queue<long> pq(arr,arr+n);
    for(int i=0;i<k;i++){
        long temp = pq.top();
        pq.pop();
        if(temp%3!=0){
            temp/=3;
            temp++;
        }
        else{
            temp/=3;
        }
        pq.push(temp);
    }
    long double avg = s/n;
    cout<<fixed<<setprecision(6)<<avg<<" ";
    s = 0;
    while(!pq.empty()){
        s+=pq.top();
        pq.pop();
    }
    avg = s/n;
    cout<<fixed<<setprecision(6)<<avg<<endl;
    return 0;
}
