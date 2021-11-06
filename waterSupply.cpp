#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    vector<pair<int,int> >edges(n-1);
    for(int i=0;i<(n-1);i++){
        cin>>edges[i].first>>edges[i].second;
    }
    int arr[n+2];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxLength = 0,currLength = 0,prevLen = 0;
    bool terminal = false;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            currLength++;
        }
        else if(arr[i] == 1 && i!=(n-1)){
            if(arr[i+1]!=0){
                prevLen = 0;
            }
            else if(arr[i+1] == 0){
                prevLen = currLength;
            }
            currLength = 0;
        }
        maxLength = max(prevLen+currLength,maxLength);
    }
    cout<<maxLength+1<<endl;
}
