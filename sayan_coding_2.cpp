#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define ff first
#define ss second
typedef pair<int,int> pii;
/*
2
10 13 4
2 5 8 6
4 6 3 5
5 10 2
9 9
3 3
*/
vector<vector<int>> dp;
string solve2(int duration,int secretMarks,int n,vector<int> marks,vector<int> time){
	dp.resize(n+1);
	for(int i=0;i<=n;i++){
		dp[i].resize(duration+1);
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=duration;j++){
			dp[i][j] = 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=duration;j++){
			dp[i][j] = dp[i][j-1];
			if(j >= time[i-1]){
				dp[i][j] = max(dp[i][j-1],dp[i-1][j-time[i-1]] + marks[i-1]);
			}
		}
	}
	return (dp[n][duration] >= secretMarks) ? "YES" : "NO";
}
string solve(int duration,int secretMarks,int n,vector<int> marks,vector<int> time){
	if(n <= 1000){
		return solve2(duration,secretMarks,n,marks,time);
	}
	vector<pii> question(n);
	for(int i=0;i<n;i++){
		question[i] = {marks[i],time[i]};
	}
	sort(question.begin(),question.end(),[](pii &p1,pii &p2){
		int x1 = p1.ff,y1 = p1.ss,x2 = p2.ff,y2 = p2.ss;
		double val1 = ((double)x1/y1),val2 = ((double)x2/y2);
		if(val1 == val2){
			return x1 > x2;
		}
		return val1 > val2;
	});
	map<int,int> maxMarks;
	maxMarks[0] = 0;
	for(int i=0;i<n;i++){
		if(question[i].ss > duration){
			continue;
		}
		else{
			auto it = maxMarks.upper_bound(duration - question[i].ss);
			--it;
			int tm = it->first,marksTime = it->second;
			if((marksTime + question[i].ff) >= secretMarks){
				return "YES";
			}
			if(!maxMarks.count(tm+question[i].ss)){
				maxMarks[tm+question[i].ss] = marksTime + question[i].ff;
			}else{
				maxMarks[tm+question[i].ss] = max(maxMarks[tm+question[i].ss],marksTime + question[i].ff);
			}
		}
	}
	return "NO";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		int duration,secretMarks,n;
		cin >> duration >> secretMarks >> n;
		vector<int> marks(n);
		vector<int> time(n);
		for(int &i:marks){
			cin >> i;
		}
		for(int &i:time){
			cin >> i;
		}
		cout << solve(duration,secretMarks,n,marks,time) << "\n";
	}
	return 0;
}