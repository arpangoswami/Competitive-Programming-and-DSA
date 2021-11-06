#include<bits/stdc++.h>
using namespace std;
int main(void){
    long rows,people;
    cin>>rows>>people;
    long *arr = new long[rows];
    for(long i = 0;i<rows;i++) cin>>arr[i];
    priority_queue<long> pq(arr,arr+rows);
    long cost = 0;
    int sold = 0;
    while(!pq.empty() && sold<people){
        long price = pq.top();
        pq.pop();
        cost+=(price);
        sold++;
        price--;
        if(price>0){
            pq.push(price);
        }
    }
    cout<<cost<<endl;
    delete []arr;
}
