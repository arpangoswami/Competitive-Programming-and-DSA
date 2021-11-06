/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/largest-subsequence-c554fb8c/description/
Sartaj's partner, Katekar is very loyal to his job and also to Sartaj. In his dedication towards his duty, he often neglects his wife who ends up alone and sad. Today, katekar has promised his wife to reach home early and spend time with her. However he and Sartaj are stuck with a problem which may decide the future of Mumbai. As Katekar cannot leave in such a situation, help him to solve the problem so that he can get back to his wife. 

You are given an array  of length . You need to detemine the largest subsequence  from the given array  such that for any index  and  in  if  then the frequency of  is strictly greater than the frequency of .

Input format :

First line : a single integer  denoting the length of given array.
Second line :  space seperated integers denoting the array elements.
Output fromat :

Print the length of largest subsequence  that can be formed.
Constraints :

 

SAMPLE INPUT 
5
1 2 2 3 3
SAMPLE OUTPUT 
3
Explanation
One possible subsequence is {1,2,2}.

Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	map<int,int> freq_map;
	int max_freq = 1;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		freq_map[x]++;
		max_freq = max(max_freq,freq_map[x]);
	}
	n = freq_map.size();
	vector<vector<int>>dp(n+1,vector<int>(max_freq+1,0));
	int i=1;
	for(auto it=freq_map.begin();it!=freq_map.end();++it){
		int num = it->first;
		int curr_freq = it->second;
		for(int j=1;j<=max_freq;j++){
			if(j<=curr_freq){
				dp[i][j] = dp[i-1][j-1] + j;
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
		i++;
	}
	cout<<dp[n][max_freq]<<"\n";
	return 0;
}