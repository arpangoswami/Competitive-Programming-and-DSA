#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
typedef array<int,3> ar;
int solve(ar a1,vector<int> &notes,vector<int> &string,map<ar,int> &mp){
	if(a1[0] == notes.size()){
		return a1[1] - a1[2];
	}
	if(mp.count(a1)){
		return mp[a1];
	}
	int idx = a1[0],ans = 1e15;
	for(int x:string){
		ans = min(ans,solve({idx+1,max(a1[1],notes[idx] - x),min(a1[2],notes[idx] - x)},notes,string,mp));
	}
	return mp[a1] = ans;
}
void solveQuestion(){
	vector<int> strings(6);
	for(int i=0;i<6;i++){
		cin >> strings[i];
	}
	sort(strings.begin(),strings.end());
	int n = 0;
	cin >> n;
	vector<int> notes(n);
	for(int i=0;i<n;i++){
		cin >> notes[i];
	}
	map<ar,int> mp;
	int ans = 1e15;
	for(int i=0;i<6;i++){
		ans = min(ans,solve({1,notes[0] - strings[i],notes[i] - strings[i]},notes,strings,mp));
	}
	cout<<ans;
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