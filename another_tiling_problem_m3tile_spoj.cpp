/*M3TILE - LATGACH3
#dynamic-programming #bitmasks
Đọc đề đẹp hơn ở:
https://codeforces.com/group/FLVn1Sc504/contest/274710/problem/L
https://codeforces.com/group/FLVn1Sc504/contest/274501/problem/Y
English	Vietnamese
In how many ways can you tile a 3xn rectangle with 2x1 dominoes?

Here is a sample tiling of a 3x12 rectangle.

Input consists of several test cases followed by a line containing -1.
Each test case is a line containing an integer 0 ≤ n ≤ 30. For each test
case, output one integer number giving the number of possible tilings. 

SAMPLE INPUT
2
8
12
-1
SAMPLE OUTPUT
3
153
2131*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll f[10001],g[10001];
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	f[0] = 1;
	f[1] = 0;
	g[0] = 1;
	g[1] = 0;
	for(int i=2;i<=10000;i++){
		f[i] = f[i-2] + 2 * g[i-2];
		g[i] = f[i] + g[i-2];
	}
	while(true){
		int n;
		cin>>n;
		if(n == -1){
			break;
		}
		cout<<f[n]<<endl;
	}
	return 0;
}