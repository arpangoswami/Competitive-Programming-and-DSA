#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
bool check(unordered_map<int,int> &mp,int n,int val){
	int ct = 0;
	for(auto it = mp.begin();it!=mp.end();++it){
		ct+=(it->second)/val;
	}
	return (ct>=n)?true:false;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int> foodPackages(m);
	for(int i=0;i<m;i++){
		cin>> foodPackages[i];
	}
	if(m<n){
		cout<<0<<"\n";
	}
	else{
		unordered_map<int,int> mp;
		for(int i=0;i<m;i++){
			mp[foodPackages[i]]++;
		}
		int low = 1,high = m,ans = 1;
		while(low<=high){
			int mid = low + (high - low)/2;
			if(check(mp,n,mid)){
				ans = mid;
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}