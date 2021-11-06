#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
void solveQuestion(){
	int n;
	cin >> n;
	if(n & 1){
		cout<<-1<<'\n';
		return;
	}
	if(n <= 4000){
		n/=2;
		cout<<n<<'\n';
		for(int i=0;i<n;i++){
			cout<<1<<" ";
		}
		cout<<'\n';
		return;
	}
	map<int,string> mp;
	string s = "1";
	int num = 2;
	mp[num] = s;
	for(int i=2;i<=61;i++){
		s.push_back('0');
		num += (1LL << i);
		mp[num] = s;
	}
	string ans = "";
	while(n > 0){
		map<int,string>::iterator it = mp.lower_bound(n);
		if((*it).first == n){
			n = 0;
			ans += (*it).second;
		}else{
			--it;
			n -= (*it).first;
			ans += (*it).second;
		}
	}
	cout<<ans.size()<<"\n";
	for(char c:ans){
		cout<<c<<" ";
	}
	cout<<'\n';
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