#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(int argc,char const* argv[]){
    int test;
    cin>>test;
    while(test--){
        long profit = 0;
        int n;
        cin>>n;
        long *arr = new long[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n,greater<int>());
        for(int i=0;i<n;i++){
            if((arr[i]-i)>0){
                profit = (profit%mod + (arr[i]-i)%mod)%mod;
            }
            else{
                break;
            }
        }
        cout<<profit%mod<<endl;
        delete []arr;
    }
    return 0;
}
