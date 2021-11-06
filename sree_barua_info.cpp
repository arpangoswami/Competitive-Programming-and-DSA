#include <bits/stdc++.h>
using namespace std;
int findMax(string S,string types){
	set<char> groups[3];
	for(int i=0;i<types.size();i++){
		groups[types[i]-'0'].insert('a'+i);
	}
	int ans = 1,mod = 1e9+7,n = S.size();
	for(int i=0;i<n;i++){
		if(S[i] == '?'){
			int possible = 26;
			vector<bool> present(3,false);
			if(i > 0){
				if(groups[0].count(S[i-1])){
					present[0] = true;
				}else if(groups[1].count(S[i-1])){
					present[1] = true;
				}else{
					present[2] = true;
				}
			}
			if(i < (n-1)){
				if(groups[0].count(S[i+1])){
					present[0] = true;
				}else if(groups[1].count(S[i+1])){
					present[1] = true;
				}else{
					present[2] = true;
				}
			}
			//cout<<"possible: "<<possible<<"\n";
			for(int i=0;i<3;i++){
				possible -= (groups[i].size() * present[i]);
			}
			ans *= possible;
			ans %= mod;
		}
		
	}
	return ans;
}
int main(){
	cout<<findMax("gpih","20100121000121202001210200");
	cout<<findMax("l?v","10110200022001121111202222")
	return 0;
}