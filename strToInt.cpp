#include<iostream>
using namespace std;
int pow(int a,int b){
    if(b==0) return 1;
    if(b&1) return a*pow(a,b/2)*pow(a,b/2);
    return pow(a,b/2)*pow(a,b/2);
}
int strToInt(string s,int n){
    if(n==1) return (s[0]-48);
    int y = strToInt(s.substr(1),n-1);
    int x = s[0]-48;
    x = x*pow(10,n-1)+y;
    return x;
}
int main() {
    string s;
    cin>>s;
    cout<<strToInt(s,s.size())<<endl;
	return 0;
}
