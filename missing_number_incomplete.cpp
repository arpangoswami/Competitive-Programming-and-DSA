#include<bits/stdc++.h>
using namespace std;
int conversion(string s,int base,int value){
    for(int i=s.length()-1;i>=0;--i){

    }
}
int main(void){
    int test;
    while(test--){
        int n;
        int value=0;
        while(n--){
            int base;
            string s;
            cin>>base>>s;
            if(base!=-1){
                value=conversion(s,base,value);
            }
            else
                continue;
        }
        cout<<value<<endl;
    }
}
