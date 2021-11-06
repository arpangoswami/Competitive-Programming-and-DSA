#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
//int dp[1005][1005][11][2];
int maxSubseqWithKsubstring(string &a,string &b,int n,int m,int k,int run,int state){
	if(n <= 0 || m <= 0 || k <= 0){
		if(state == 1){
			return run;
		}
		return 0;
	}
	if(a[n-1] == b[m-1]){
		if(state == 1){
			return maxSubseqWithKsubstring(a,b,n-1,m-1,k,1+run,1);
		}else{
			return max({maxSubseqWithKsubstring(a,b,n-1,m-1,k,1,1),maxSubseqWithKsubstring(a,b,n-1,m,k,0,0),maxSubseqWithKsubstring(a,b,n,m-1,k,0,0)});
		}
	}else{
		if(state == 1){
			return run + max(maxSubseqWithKsubstring(a,b,n-1,m,k-1,0,0),maxSubseqWithKsubstring(a,b,n,m-1,k-1,0,0));
		}else{
			return max(maxSubseqWithKsubstring(a,b,n-1,m,k,0,0),maxSubseqWithKsubstring(a,b,n,m-1,k,0,0));
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,k;
	cin>>n>>m>>k;
	string a,b;
	cin>>a>>b;
	cout<<maxSubseqWithKsubstring(a,b,n,m,k,0,0)<<endl;
	return 0;
}