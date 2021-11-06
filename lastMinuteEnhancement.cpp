#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	int maxm = 0;
	map<int,int,greater<int> > mp;
	for(int &i:arr){
		cin >> i;
		mp[i]++;
	}
	int val = 2*n + 1;
	int ans = 0;
	while(val > 0){
		if(mp.count(val) == 0 && mp.count(val-1) == 0){
			val--;
		}else if(mp.count(val) == 0){
			int temp = val;
			val--;
			while(mp.count(val) && mp[val] == 1){
				ans++;
				val--;
			}
			if(mp.count(val) && mp[val] >= 2){
				ans+=2;
				mp[temp]++;
				mp[val]--;
				val--;
			}
		}else{
			ans++;
			val--;
		}
	}
	cout<<mp.size()<<'\n';
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