#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<string,int> pii;
bool cmp(pii &p1,pii &p2){
	if(p1.second == p2.second){
		return p1.first < p2.first;
	}
	return p1.second > p2.second;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int x;
	cin >> x;
	int n;
	cin >> n;
	vector<pii> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].first >> arr[i].second;
	}
	vector<pii> temp;
	for(int i=0;i<n;i++){
		if(arr[i].second >= x){
			temp.push_back(arr[i]);
		}
	}
	sort(temp.begin(),temp.end(),cmp);
	for(pii x:temp){
		cout<<x.first<<" "<<x.second<<"\n";
	}
	return 0;
}