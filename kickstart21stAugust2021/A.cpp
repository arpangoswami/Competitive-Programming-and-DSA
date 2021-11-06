#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	string s;
	cin >> s;
	int N = s.size();
	vi freq(26);
	int maxFreq = 0,letter = 0;
	for(char c:s){
		freq[c-'a']++;
		if(freq[c - 'a'] > maxFreq){
			maxFreq = freq[c - 'a'];
			letter = c - 'a';
		}
	}
	if(maxFreq > N/2){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	string copy = s;
	char temp = s.back();
	if(N & 1){
		copy.pop_back();
	}
	map<char,vector<int>> pos;
	int n = copy.size();
	for(int i=0;i<N;i++){
		pos[s[i]].push_back(i);
	}
	sort(copy.begin(),copy.end());
	string s1 = copy.substr(0,(n/2));
	string s2 = copy.substr(n/2);
	vector<int> ps1,ps2;
	vector<int> idx(26);
	for(char c:s1){
		ps1.push_back(pos[c][idx[c-'a']]);
		idx[c-'a']++;
	}
	for(char c:s2){
		ps2.push_back(pos[c][idx[c-'a']]);
		idx[c-'a']++;
	}
	string copy2 = s;
	for(int i=0;i<ps1.size();i++){
		swap(copy2[ps1[i]],copy2[ps2[i]]);
	}
	if(N > n){
		for(int i=0;i<n;i++){
			if(s[i] != temp && copy2[i] != temp){
				swap(copy2[n],copy2[i]);
				break;
			}
		}
		cout<<copy2<<"\n";
	}else{
		cout<<copy2<<"\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}