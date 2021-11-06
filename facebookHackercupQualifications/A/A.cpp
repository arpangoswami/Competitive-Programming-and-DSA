#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
void solveQuestion(){
	string s;
	cin >> s;
	vector<int> freq(26);
	int vowel = 0,cons = 0;
	set<char> vow;
	vow.insert('A');
	vow.insert('E');
	vow.insert('I');
	vow.insert('O');
	vow.insert('U');
	for(char c:s){
		freq[c - 'A']++;
		if(vow.count(c)){
			vowel++;
		}else{
			cons++;
		}
	}
	int ans = 2*s.size();
	for(int i=0;i<26;i++){
		if(vow.count('A'+i)){
			ans = min(ans,2*(vowel - freq[i]) + cons);
		}else{
			ans = min(ans,2*(cons - freq[i]) + vowel);
		}
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	#ifndef ONLINE_JUDGE

	freopen("A_1_input.txt", "r", stdin);

	freopen("A_1_output.txt", "w", stdout);

	#endif // ONLINE_JUDGE




	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}