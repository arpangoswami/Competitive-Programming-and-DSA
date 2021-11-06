/*https://cses.fi/problemset/task/1633
Time limit: 1.00 s Memory limit: 512 MB
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and 6.

For example, if n=3, there are 4 ways:
1+1+1
1+2
2+1
3
Input

The only input line has an integer n.

Output

Print the number of ways modulo 109+7.

Constraints
1≤n≤106
Example

Input:
3

Output:
4*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
const ll mod = 1e9+7;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<ll> ways(n+1,0);
	ways[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++){
			if(i>=j){
				ways[i]+=ways[i-j];
				ways[i]%=mod;
			}
		}
	}
	cout<<ways[n]<<endl;
	return 0;
}