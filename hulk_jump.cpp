#include<bits/stdc++.h>
using namespace std;
int count_set(int n){
    int coun = 0;
    for(int i = n;i>0;i>>=1){
        if(i&1)
            coun++;
    }
    return coun;
}
int main(void) {
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        cout<<count_set(n)<<endl;
    }
}
