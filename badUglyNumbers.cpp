#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        string s = "23";
        int idx = 2;
        while(idx<n){
            s.push_back('3');
            idx++;
        }
        cout<<s<<endl;
    }
}
