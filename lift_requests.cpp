#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,q;
        cin>>n>>q;
        long long floor = 0;
        long long steps = 0;
        while(q--){
            long long x,y;
            cin>>x>>y;
            steps+=(abs(x-floor));
            steps+=(abs(y-x));
            floor = y;
        }
        cout<<steps<<endl;
    }
}
