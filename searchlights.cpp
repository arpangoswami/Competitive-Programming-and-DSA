/*
D. Searchlights
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n robbers at coordinates (a1,b1), (a2,b2), ..., (an,bn) and m searchlight at coordinates (c1,d1), (c2,d2), ..., (cm,dm).

In one move you can move each robber to the right (increase ai of each robber by one) or move each robber up (increase bi of each robber by one). Note that you should either increase all ai or all bi, you can't increase ai for some points and bi for some other points.

Searchlight j can see a robber i if ai≤cj and bi≤dj.

A configuration of robbers is safe if no searchlight can see a robber (i.e. if there is no pair i,j such that searchlight j can see a robber i).

What is the minimum number of moves you need to perform to reach a safe configuration?

Input
The first line of input contains two integers n and m (1≤n,m≤2000): the number of robbers and the number of searchlight.

Each of the next n lines contains two integers ai, bi (0≤ai,bi≤106), coordinates of robbers.

Each of the next m lines contains two integers ci, di (0≤ci,di≤106), coordinates of searchlights.

Output
Print one integer: the minimum number of moves you need to perform to reach a safe configuration.

Examples
inputCopy
1 1
0 0
2 3
outputCopy
3
inputCopy
2 3
1 6
6 1
10 1
1 10
7 7
outputCopy
4
inputCopy
1 2
0 0
0 0
0 0
outputCopy
1
inputCopy
7 3
0 8
3 8
2 7
0 10
5 5
7 0
3 5
6 6
3 11
11 5
outputCopy
6
Note
In the first test, you can move each robber to the right three times. After that there will be one robber in the coordinates (3,0).

The configuration of the robbers is safe, because the only searchlight can't see the robber, because it is in the coordinates (2,3) and 3>2.

In the second test, you can move each robber to the right two times and two times up. After that robbers will be in the coordinates (3,8), (8,3).

It's easy the see that the configuration of the robbers is safe.

It can be proved that you can't reach a safe configuration using no more than 3 moves.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	vector<pii> robbers(n);
	vector<pii> searchlight(m);
	for(int i=0;i<n;i++){
		cin >> robbers[i].first >> robbers[i].second;
	}
	for(int i=0;i<m;i++){
		cin >> searchlight[i].first >> searchlight[i].second;
	}
	vector<int> min_dist(1000001);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(searchlight[j].first >= robbers[i].first && searchlight[j].second >= robbers[i].second){
				int dist1 = searchlight[j].first - robbers[i].first;
				int dist2 = searchlight[j].second - robbers[i].second;
				min_dist[dist1] = max(min_dist[dist1],dist2 + 1);//if i take dist1 steps to right i need to take dist2 + 1 steps up to avoid searchlight[j]
			}
		}
	}
	int ans = 1e9,curr = 0;
	for(int i=1e6;i>=0;i--){
		curr = max(curr,min_dist[i]);//need to take at least curr steps up 
		// suffix maximums taking less than or equals dist1 steps to the right,hence need to take at least dist2 steps up
		ans = min(ans,i+curr);//i steps to the right curr steps up
	}
	cout<<ans<<"\n";

}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}