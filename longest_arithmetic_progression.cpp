#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,unordered_map<int,int>> pii;
int longestArithmeticProgression(vector<int> &A){
    if(A.size()<=2){
       return A.size();
    }
    int n = A.size();
    vector<pii>dp(n);
    dp[0].first = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int diff = A[i] - A[j];
            int freq_there = dp[j].second[diff];
            dp[i].second[diff] = freq_there + 1;
        }
        int mm = 2;
        for(auto it = dp[i].second.begin();it!=dp[i].second.end();++it){
            mm = max(mm,it->second + 1);
        }
        dp[i].first = mm;
    }
    int maxi = 2;
    for(int i=0;i<n;i++){
        maxi = max(maxi,dp[i].first);
    }
    return maxi;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++) cin>>arr[i];
		cout<<longestArithmeticProgression(arr)<<endl;
	}
	return 0;
}