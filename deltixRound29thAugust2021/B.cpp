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
typedef long double ld;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	vi odds,evens;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		if(arr[i] % 2){
			odds.push_back(i);
		}else{
			evens.push_back(i);
		}
	}
	vi pos((n+1)/2);
	pos[0] = 0;
	int id = 1;
	while(id < pos.size()){
		pos[id] = pos[id-1] + 2;
		id++;
	}
	if(n % 2){
		int diff = abs((int)odds.size() - (int)evens.size());
		if(diff > 1){
			cout<<"-1\n";
			return;
		}
		int ans = 0;
		if(odds.size() > evens.size()){
			int sz = (n+1)/2;
			for(int i=0;i<sz;i++){
				ans += abs(pos[i] - odds[i]);
			}	
		}else{
			int sz = (n+1)/2;
			for(int i=0;i<sz;i++){
				ans += abs(pos[i] - evens[i]);
			}
		}
		cout<<ans<<"\n";
	}else{
		int diff = abs((int)odds.size() - (int)evens.size());
		if(diff > 0){
			cout<<"-1\n";
			return;
		}
		int ans1 = 0,ans2 = 0;
		int sz = n/2;
		for(int i=0;i<sz;i++){
			ans1 += abs(pos[i] - odds[i]);
		}
		for(int i=0;i<sz;i++){
			ans2 += abs(pos[i] - evens[i]);
		}
		cout << min(ans1,ans2) << "\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}