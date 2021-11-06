#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int test;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        ll *arr = new ll[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        unordered_set<ll> visited;
        bool flag = false;
        for(int i=0;i<n;i++){
            ll next = i + arr[i];
            next = ((next%n) + n)%n;
            if(visited.count(next)){
                flag = true;
                break;
            } 
            visited.insert(next);
        }
        if(flag){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
        delete []arr;
    }
    return 0;
}