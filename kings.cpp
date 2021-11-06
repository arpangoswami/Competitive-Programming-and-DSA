#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(k==0){
            continue;
        }
        priority_queue<int> pq;
        for(int i=0;i<(n-k+1);i++){
            pq.push(arr[i]);
        }
        cout<<pq.top()<<" ";
        pq.pop();
        int c = 1;
        for(int i = (n-k+1);i<n;i++){
            if(c == k){
                break;
            }
            pq.push(arr[i]);
            cout<<pq.top()<<" ";
            pq.pop();
            c++;
        }
        cout<<endl;
    }
}
