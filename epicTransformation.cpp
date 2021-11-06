#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	map<int,int> mp;
	int maxFreq = 1;
	for(int &i:arr){
		cin >> i;
		mp[i]++;
		maxFreq = max(maxFreq,mp[i]);
	}
	if(maxFreq <= n/2){
		cout << (n&1) << '\n';
	}else{
		int others = (n - maxFreq);
		cout << n - 2 * others<< '\n';
	}
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