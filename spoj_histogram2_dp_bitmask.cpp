/*
HIST2 - Histogram
#dynamic-programming #bitmasks
In statistics, a histogram is a graphical display of tabulated frequencies, shown as bars.
It shows what proportion of cases fall into each of several categories. 
It is a polygon composed of a sequence of rectangles aligned at a common base line. 
In this problem all rectangles have a width of unit length. But their heights are distinct. 
Some permutation of the heights will give the maximum perimeter. 
Your task is to find the maximum perimeter of the histogram and the number of permutations that give the maximum perimeter.


In the image Figure (a) shows a histogram with heights {1,2,3,4} (1st sample testcase) and has a perimeter of 16 units. 
Figure (b) shows one of the permutations {3,1,2,4} having the maximum perimeter of 20 units.

Input
Input consists of multiple test cases. Each test case describes a histogram and starts with an integer N, 2 ≤ N ≤ 15, 
denoting the number of rectangles it is composed of. Next line consists of N space separated positive integers representing the 
heights of the rectangles. All heights are distinct and less than or equal to 100. N=0 indicates the end of tests. There are atmost 50 test cases.

Output
For each test case output the maximum possible perimeter of the histogram and the number of permutations that give maximum 
perimeter in a single line, separated by a single space.

Example
Input:
4
1 2 3 4
3
2 6 5
0

Output:
20 8
24 2

*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> arr;
int N;
int dp[16][(1 << 15) + 1];
int cnt[16][(1<<15) + 1];
int solve(int prev,int mask){
	if(mask == (1<<N)-1){
		cnt[prev][mask] = 1LL;
		return dp[prev][mask] = arr[prev];
	}
	if(dp[prev][mask] != -1){
		return dp[prev][mask];
	}
	int ans = 0;
	for(int i=0;i<N;i++){
		if(mask & (1 << i)){
			continue;
		}else{
			int temp = abs(arr[i] - arr[prev]) + solve(i,mask | (1<<i));
			if(temp > ans){
				cnt[prev][mask] = 0LL;
				ans = temp;
			}
			if(temp == ans){
				cnt[prev][mask] += cnt[i][mask | (1<<i)];
			}
		}
	}
	return dp[prev][mask] = ans;
}
void solveQuestion(){
	arr.resize(N);
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	for(int i=0;i<=N;i++){
		for(int j=0;j<=(1 << 15);j++){
			dp[i][j] = -1;
			cnt[i][j] = 0LL;
		}
	}
	int maxPm = 0,count = 0LL;
	for(int i=0;i<N;i++){
		int ans = arr[i]+solve(i,1<<i);
		if(ans > maxPm){
			maxPm = ans;
			count = 0;
		}
		if(ans == maxPm){
			count += cnt[i][1<<i];
		}
	}
	maxPm += 2*N;
	cout<<maxPm<<" "<<count<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while(true){
		cin >> N;
		if(N == 0){
			break;
		}
		solveQuestion();
	}
	return 0;
}