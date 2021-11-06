#include<iostream>
#include<cstring>
using namespace std;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void printKeypad(string s,string ans,int index,int n){
    if(index==n){
        cout<<ans<<endl;
        return;
    }
    int digit = s[index]-48;
    for(int i=0;i<table[digit].size();i++){
        printKeypad(s,ans+table[digit][i],index+1,n);
    }
}
int main() {
    string s;
    cin>>s;
    printKeypad(s,"",0,s.size());
	return 0;
}
