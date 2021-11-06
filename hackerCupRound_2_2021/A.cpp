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
	int n,m;
	cin >> n >> m;
	map<int,int> unChanged;
	map<int,int> changed;
	vector<int> arr(m);
	for(int i=0;i<m;i++){
		cin >> arr[i];
		unChanged[arr[i]]++;
	}
	int ans = 0;
	for(int j=0;j<n;j++){
		vector<int> temp(m);
		map<int,int> freq;
		for(int i=0;i<m;i++){
			cin >> temp[i];
			freq[temp[i]]++;
		}
		map<int,int> changeTemp;
		map<int,int> unChangeTemp;
		//those who have used the free transform try to maintain same dress
		for(auto &it:freq){
			if(changed.count(it.first)){
				int cnt = min(it.second,changed[it.first]);
				it.second -= cnt;
				changeTemp[it.first] = cnt;
				changed[it.first] -= cnt;
			}
		}
		//those who have NOT used the free transform try to maintain same dress
		
		for(auto &it:freq){
			if(unChanged.count(it.first)){
				int cnt = min(it.second,unChanged[it.first]);
				it.second -= cnt;
				unChangeTemp[it.first] = cnt;
				unChanged[it.first] -= cnt;
			}
		}
		//those who have NOT used their free change use their free change NOW
		auto itr1 = unChanged.begin(),itr2 = freq.begin();
		for(;itr1 != unChanged.end() && itr2 != freq.end();){
			int cnt = min(itr1->second,itr2->second);
			changeTemp[itr2->first] += cnt;
			if(itr1->second < itr2->second){
				itr1->second -= cnt;
				itr2->second -= cnt;
				int v = itr1->first;
				itr1++;
			}else if(itr1->second > itr2->second){
				itr1->second -= cnt;
				itr2->second -= cnt;
				int v = itr2->first;
				itr2++;
			}else{
				itr1->second -= cnt;
				itr2->second -= cnt;
				int v1 = itr1->first;
				int v2 = itr2->first;
				itr1++;
				itr2++;
			}
		}
		//have to manually change these folks
		itr2 = freq.begin();
		itr1 = changed.begin();
		for(;itr1 != changed.end() && itr2 != freq.end();){
			int cnt = min(itr1->second,itr2->second);
			ans += cnt;
			changeTemp[itr2->first] += cnt;
			if(itr1->second < itr2->second){
				itr1->second -= cnt;
				itr2->second -= cnt;
				int v = itr1->first;
				itr1++;
			}else if(itr1->second > itr2->second){
				itr1->second -= cnt;
				itr2->second -= cnt;
				int v = itr2->first;
				itr2++;
			}else{
				itr1->second -= cnt;
				itr2->second -= cnt;
				int v1 = itr1->first;
				int v2 = itr2->first;
				itr1++;
				itr2++;
			}

		}
		changed = changeTemp;
		unChanged = unChangeTemp;
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	#ifndef ONLINE_JUDGE

	freopen("A_val_input.txt", "r", stdin);

	freopen("A_val_output.txt", "w", stdout);

	#endif
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}