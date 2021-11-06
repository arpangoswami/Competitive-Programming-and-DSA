#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a;
	vector<int> t;
	vector<int> g;
	vector<int> c;
	for(int i=0;i<n;i++){
		if(s[i] == 'A'){
			a.push_back(i);
		}else if(s[i] == 'T'){
			t.push_back(i);
		}else if(s[i] == 'G'){
			g.push_back(i);
		}else{
			c.push_back(i);
		}
	}
	
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