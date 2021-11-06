#include<bits/stdc++.h>
using namespace std;
int main(void) {
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='5'){
			s[i]='9'-s[i]+48;
		}
	}
	if (s.front() == '0')
        s.front() = '9';
	cout<<s;
}
