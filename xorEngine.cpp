#include<bits/stdc++.h>
using namespace std;
int countSetBits(int n){
    int c = 0;
    for(int i=0;i<32;i++){
        if((n>>i)&1){
            c++;
        }
    }
    return c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int q;
        cin>>q;
        int *arr = new int[n];
        int odd = 0,even = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            int c = countSetBits(arr[i]);
            if(c&1){
                odd++;
            }
            else{
                even++;
            }
        }
        while(q--){
            int a;
            cin>>a;
            int ct = countSetBits(a);
            if(ct&1){
                cout<<odd<<" "<<even<<"\n";
            }
            else{
                cout<<even<<" "<<odd<<"\n";
            }
        }
        delete []arr;
    }
    return 0;
}
