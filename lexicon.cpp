#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        string s;
        cin>>s;
        bool flag = false;
        int length = s.length();
        for(int i=(length-1);i>=1;i--){
            if(int(s[i])>int(s[i-1])){
                swap(s[i],s[i-1]);
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<s<<endl;
        }
        else{
            cout<<"no answer"<<endl;
        }
    }
}
