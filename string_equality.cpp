#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	string s1,s2;
	cin >> s1 >> s2;
	vector<int> freq1(26);
	vector<int> freq2(26);
	for(char c:s1){
		freq1[c - 'a']++;
	}
	for(char c:s2){
		freq2[c - 'a']++;
	}
	for(int i=0;i<26;i++){
		int sub = min(freq1[i],freq2[i]);
		freq1[i] -= sub;
		freq2[i] -= sub;
	}
	for(int i=0;i<26;i++){
		if(freq1[i] % k != 0){
			cout<<"No"<<'\n';
			return;
		}
	}
	for(int i=0;i<26;i++){
		if(freq2[i] % k!=0){
			cout<<"No"<<'\n';
			return;
		}
	}
	for(int i=0;i<26;i++){
		for(int j=i+1;j<26 && freq1[i] > 0;j++){
			int sub = min(freq1[i],freq2[j]);
			freq1[i] -= sub;
			freq2[j] -= sub;
		}
		if(freq1[i] > 0){
			cout<<"No"<<'\n';
			return;
		}
	}
	cout<<"Yes"<<'\n';
	return;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}