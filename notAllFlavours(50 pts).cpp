#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int max_length = 1, curr_length = 1;
        for(int i=0;i<(n-1);i++){
            if(arr[i]!=arr[i+1]){
                curr_length = 1;
            }
            else{
                curr_length++;
                max_length = max(max_length,curr_length);
            }
        }
        cout<<max_length<<endl;
        delete []arr;
    }
}
