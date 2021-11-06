#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
inline int calSum(vector<int> &arr,int low,int high){
	if(low > high){
		return 0;
	}
	if(low > 0){
		return arr[high] - arr[low-1];
	}
	return arr[high];
}
int check(vector<int> &pref,vector<int> &freq,int minFreq,int maxFreq,int n,int inf){
	int ans = inf;
	for(int i=minFreq;i<=maxFreq;i++){
		int temp = 0;
		auto it = lower_bound(freq.begin(),freq.end(),i);
		if(it != freq.begin()){
			it--;
			int idx = it - freq.begin();
			//cout<<"idx here: "<<idx<<'\n';
			temp += calSum(pref,0,idx);
			//cout<<"freq considered: "<<i<<" lower ones: "<<temp<<'\n';
		}
		it = upper_bound(freq.begin(),freq.end(),i);
		if(it != freq.end()){
			int idx = it - freq.begin();
			int higher = (calSum(pref,idx,n-1) - (n-idx)*i);
			//cout<<"freq considered: "<<i<<" higher ones: "<<higher<<'\n';
			temp += higher;
		}
		//cout<<"freq considered: "<<i<<" both: "<<temp<<'\n';
		ans = min(ans,temp);
	}
	return ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		int v;
		cin >> v;
		mp[v]++;
	}
	vector<int> freq;
	for(auto it:mp){
		freq.push_back(it.second);
	}
	sort(freq.begin(),freq.end());
	int N = freq.size();
	vector<int> pref(N);
	int maxm = freq[N-1],minm = freq[0];
	pref[0] = freq[0];
	for(int i=1;i<N;i++){
		pref[i] = freq[i] + pref[i-1];
	}
	// for(int x:freq){
	// 	cout<<x<<" ";
	// }
	// cout<<'\n';
	// for(int x:pref){
	// 	cout<<x<<" ";
	// }
	// cout<<'\n';
	int ans = check(pref,freq,minm,maxm,N,n);
	cout<<ans<<'\n';
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