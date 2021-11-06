#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<string> twoPowers;
void pre(){
	for(int i=0;i<=60;i++){
		twoPowers.push_back(to_string(1LL << i));
	}
}
int minOps(const string &s1,const string &s2){
	int n1 = s1.size(),n2 = s2.size();
	int i = 0,j = 0;
	while(i < n1 && j < n2){
		if(s1[i] == s2[j]){
			i++;
			j++;
		}else{
			i++;
		}
	}
	return n1 + n2 - 2*j;
}
void solveQuestion(){
	string s;
	cin >> s;
	int ans = s.size() + 1;
	for(string x:twoPowers){
		ans = min(ans,minOps(s,x));
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	pre();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}