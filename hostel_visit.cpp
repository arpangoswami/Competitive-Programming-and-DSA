#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n,k;
    cin>>n>>k;
    long *arr = new long[k];
    for(int i=0;i<k;i++){
        long type,x,y;
        cin>>type>>x>>y;
        arr[i] = (x*x) + (y*y);
    }
    priority_queue<long> pq(arr,arr+k);
    delete []arr;
    int temp = n-k;
    while(temp--){
        int type;
        cin>>type;
        if(type == 1){
            long x,y;
            cin>>x>>y;
            long dist = (x*x+y*y);
            if(dist<pq.top()){
                pq.pop();
                pq.push(dist);
            }
            else{
                continue;
            }
        }
        else{
            cout<<pq.top()<<endl;
        }
    }
}
