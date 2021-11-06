#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	set<char> st;
	for(int i=0;i<k;i++){
		char c;
		cin >> c;
		st.insert(c);
	}
	int unsafe = 0;
	for(char c:s){
		if(!st.count(c)){
			unsafe++;
		}
	}
	if(unsafe == 0){
		cout << (n * (n+1))/2;
		return;
	}
	vector<int> unsafeIdx(unsafe);
	int ptr = 0;
	for(int i=0;i<n;i++){
		if(!st.count(s[i])){
			unsafeIdx[ptr++] = i;
		}
	}
	int ans = 0;
	for(int i=1;i<unsafe;i++){
		int length = unsafeIdx[i] - unsafeIdx[i-1] - 1;
		ans += (length * (length + 1))/2;
	}
	ans += (unsafeIdx[0] * (unsafeIdx[0] + 1))/2;
	//cout << "ans1: "<<ans<<'\n';
	int lenLast = (n - unsafeIdx.back() - 1);
	ans += (lenLast * (lenLast + 1))/2;
	cout<<ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}