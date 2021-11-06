#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	string s;
	cin >> s;
	string ans;
	unordered_set<char> st;
	for(char c:s){
		st.insert(c);
		if(st.size() == 4){
			ans.push_back(c);
			st.clear();
		}
	}
	if(st.count('A') == 0){
		ans.push_back('A');
	}else if(st.count('T') == 0){
		ans.push_back('T');
	}else if(st.count('G') == 0){
		ans.push_back('G');
	}else{
		ans.push_back('C');
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}