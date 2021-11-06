#include<iostream>
using namespace std;
string dup_charChange(string s){
    if(s.size()==2 && s[0]==s[1]){
        s.insert(1,"*");
        return s;
    }
    if(s.size()==1) return s;
    if(s[0]==s[1]){
        s.insert(1,"*");
        return s.substr(0,2)+dup_charChange(s.substr(2));
    }
    else{
        return s[0]+dup_charChange(s.substr(1));
    }
}
int main(void){
    string s;
    cin>>s;
    s = dup_charChange(s);
    cout<<s;
}
