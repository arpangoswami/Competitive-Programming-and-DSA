#include<bits/stdc++.h>
using namespace std;
struct event{
    int index;
    int left;
    int right;
    int qval;
};
bool compare (event a,event b){
    if( a.qval == b.qval)
        return (a.left>b.left);
    return a.qval>b.qval;
}
int main(void){
    int n;
    cin>>n;
    int *arr = new int [n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int q;
    cin>>q;
    event *values = new event [q];
    int *BIT = new int[n+1];
    for(int i=0;i<q;i++){
        cin>>values[i].left>>values[i].right>>values[i].big;
        values[i].index = i;
    }
    sort(values,values+q,compare);
    for(int i=1;i<=n;i++){

    }
}
