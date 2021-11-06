#include <bits/stdc++.h>
#define int long long
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
int firstIdx(const string &s,int n,char c){
	for(int i=0;i<n;i++){
		if(s[i] == c){
			return i;
		}
	}
	return n;
}
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	int start = 0;
	int fIdxX = firstIdx(s,n,'X'),fIdxO = firstIdx(s,n,'O');
	if(fIdxX == fIdxO){
		cout<<"0\n";
		return;
	}
	if(fIdxO < fIdxX){
		start ^= 1;
	}	
	for(char c:s){
		if(c == 'O' && start == 0){
			ans++;
			start ^= 1;
		}else if(c == 'X' && start == 1){
			ans++;
			start ^= 1;
		}
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	#ifndef ONLINE_JUDGE

	freopen("A_input.txt", "r", stdin);

	freopen("A_output.txt", "w", stdout);

	#endif
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}