#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<string> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	vector<int> freq(26);
	for(int i=0;i<n;i++){
		for(char c:arr[i]){
			freq[c-'a']++;
		}
	}
	bool f = true;
	for(int i=0;i<26;i++){
		if(freq[i]%n!=0){
			f = false;
			break;
		}
	}
	string ans = f ? "YES" : "NO";
	cout<<ans<<"\n";
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