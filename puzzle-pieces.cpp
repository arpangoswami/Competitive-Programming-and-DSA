#include<bits/stdc++.h>
using namespace std;
void solve(int n,int m){
    if(n == 1 || m == 1){
        cout<<"YES"<<endl;
        return;
    }
    else if(m == 2 && n == 2){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}
int main(int argc,char const* argv[]){
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        solve(n,m);
    }
    return 0;
}