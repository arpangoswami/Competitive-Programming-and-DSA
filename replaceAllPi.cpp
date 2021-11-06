#include<iostream>
using namespace std;
string replacePi(string s){
    if(s.size()<=1){
        return s;
    }
    if(s[0]!='p' || (s[0]=='p' && s[1]!='i')){
        return s[0]+replacePi(s.substr(1));
    }
    if(s[0]=='p'&&s[1]=='i'){
        return "3.14"+replacePi(s.substr(2));
    }
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        string s;
        cin>>s;
        s = replacePi(s);
        cout<<s<<endl;
    }
}
