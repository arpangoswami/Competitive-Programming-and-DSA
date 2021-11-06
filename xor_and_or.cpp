#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	string t;
	cin>>s;
	cin>>t;
	int m = s.size(),n = t.size();
	if(m!=n){
		cout<<"NO"<<endl;
	}else{
		bool flag = true;
		bool allZeroes = true;
		for(int i=0;i<n;i++){
			if(s[i] != '0'){
				allZeroes = false;
				break;
			}
		}
		if(allZeroes){
			for(int i = 0;i<n;i++){
				if(t[i] != '0'){
					flag = false;
					break;
				}
			}
		}
		if(!allZeroes){
			bool f = true;
			for(int i=0;i<n;i++){
				if(t[i] != '0'){
					f = false;
					break;
				}
			}
			if(f){
				flag = false;
			}
		}
		cout<<(flag ? "YES":"NO")<<endl;
	}
	return 0;
}