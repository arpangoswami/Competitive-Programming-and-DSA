#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int first = arr[0],second = max(arr[0],arr[1]);
        int ans = max(arr[0],arr[1]);
        for(int i=2;i<n;i++){
            ans = max(first+arr[i],second);
            first = second;
            second = ans;
        }
        cout<<ans<<endl;
    }
}
