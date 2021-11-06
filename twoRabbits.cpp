#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int r1Start,r2Start,r1Jump,r2Jump;
        cin>>r1Start>>r2Start>>r1Jump>>r2Jump;
        if((r2Start-r1Start)%(r1Jump+r2Jump)!=0){
            cout<<-1<<endl;
        }
        else{
            cout<<(r2Start-r1Start)/(r1Jump+r2Jump)<<endl;
        }
    }
}
