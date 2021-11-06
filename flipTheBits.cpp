#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	string s1,s2;
	cin >> n >> s1 >> s2;
	vector<int> freq(n);
	if(s1[0] == '0'){
		freq[0]++;
	}
	for(int i=1;i<n;i++){
		freq[i] = freq[i-1];
		if(s1[i] == '0'){
			freq[i]++;
		}
	}
	int flips = 0;
	for(int i=n-1;i>=0;i--){
		if((s1[i] == s2[i] && flips % 2 == 0) || (s1[i] != s2[i] && flips % 2 == 1)){
			continue;
		}
		int c2 = s2[i] - '0',c1 = s1[i] - '0';
		int zeros = freq[i];
		int ones = (i+1-zeros);
		if(zeros == ones){
			flips++;
		}else{
			cout<<"NO"<<'\n';
			return;
		}
	}
	cout<<"YES"<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}