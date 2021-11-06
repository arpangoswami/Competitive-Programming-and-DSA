/*GNY07H - Tiling a Grid With Dominoes
#dynamic-programming #bitmasks
We wish to tile a grid 4 units high and N units long with rectangles (dominoes) 2 units by one unit (in either orientation). For example, the figure shows the five different ways that a grid 4 units high and 2 units wide may be tiled.



Write a program that takes as input the width, W, of the grid and outputs the number of different ways to tile a 4-by-W grid.

Input
The first line of input contains a single integer N, (1 ≤ N ≤ 1000) which is the number of datasets that follow.

Each dataset contains a single decimal integer, the width, W, of the grid for this problem instance.

Output
For each problem instance, there is one line of output: The problem instance number as a decimal integer (start counting at one), a single space and the number of tilings of a 4-by-W grid. The values of W will be chosen so the count will fit in a 32-bit integer.

Example
Input:
3
2
3
7

Output:
1 5
2 11
3 781
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int f[1001],g[1001],h[1001];
	f[0] = 1;
	g[0] = 1;
	h[0] = 1;
	f[1] = 1;
	g[1] = 2;
	h[1] = 1;
	for(int i=2;i<=1000;i++){
		f[i] = f[i-1] + f[i-2] + 2*g[i-2] + h[i-2];
		g[i] = g[i-1] + f[i];
		h[i] = f[i] + h[i-2];
	}
	int test;
	cin>>test;
	for(int i=1;i<=test;i++){
		int idx;
		cin>>idx;
		cout<<i<<" "<<f[idx]<<endl;
	}
	return 0;
}