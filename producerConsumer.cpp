#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,demand;
        cin>>n>>demand;
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int leftOver = 0;
        bool flag = true;
        for(int i=0;i<n;i++){
            if(leftOver+arr[i]<demand){
                flag = false;
                break;
            }
            else{
                if(arr[i]>=demand){
                    leftOver+=(arr[i]-demand);
                }
                else{
                    leftOver-=(demand-arr[i]);
                }
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        delete []arr;
    }
}
