#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void solveQuestion(){
	int n,m,k;
	cin >> n >> m >> k;
	int hori = 0,vert = 0,minHort = 0;
	if(m & 1){
		vert = n/2;
		hori = (n*(m-1))/2;
	}else{
		hori = (n*m)/2;
	}
	if(n & 1){
		minHort = (m/2);
	}
	if((hori & 1) == (k & 1) && k >= minHort && k <= hori){
		cout<<"YES\n";
		vector<vector<char>> grid(n,vector<char>(m));
		if(m & 1){
			int sub = 0;
			for(int i=0;i<(n-1);i+=2){
				grid[i][m-1] = 'z' - sub;
				grid[i+1][m-1] = 'z' - sub;
				sub ^= 1;
			}
		}
		if(n & 1){
			int add = 0;
			for(int j=0;j<(m-1);j+=2){
				grid[n-1][j] = 'a' + add;
				grid[n-1][j+1] = 'a' + add;
				add ^= 1;
			}
		}
		n = (n/2) * 2,m = (m/2) * 2;
		int add = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<(m-1);j+=2){
				if(i % 4 == 0){
					grid[i][j] = 'g' + add;
					grid[i][j+1] = 'g' + add;
				}else if(i % 4 == 1){
					grid[i][j] = 'i' + add;
					grid[i][j+1] = 'i' + add;
				}else if(i % 4 == 2){
					grid[i][j] = 'k' + add;
					grid[i][j+1] = 'k' + add;
				}else{
					grid[i][j] = 'm' + add;
					grid[i][j+1] = 'm' + add;
				}
				add ^= 1;
			}
		}
		int i = 0,j = 0;
		while(hori > k){
			hori -= 2;
			swap(grid[i][j+1],grid[i+1][j]);
			j += 2;
			if(j == m){
				i += 2;
				j = 0;
			}
		}
		for(auto x:grid){
			for(char c:x){
				cout<<c;
			}
			cout<<"\n";
		}
	}else{
		cout<<"NO\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}