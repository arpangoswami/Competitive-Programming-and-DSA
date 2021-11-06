#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        long n,k;
        cin>>n>>k;
        if((n%2==0 && k%2!=0) || (n%2!=0 && k%2==0)){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            if((long)n >= (long)k*(long)k){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}
