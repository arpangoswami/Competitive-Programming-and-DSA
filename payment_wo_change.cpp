#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int a,b,n,sum;
        cin>>a>>b>>n>>sum;
        int bigCreq = sum/n;
        sum = sum - n*min(a,bigCreq);
        if(sum>b){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}
