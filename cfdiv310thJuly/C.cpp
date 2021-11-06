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
	int lines,n,m;
	cin >> lines >> n >> m;
	vi arr1(n),arr2(m);
	for(int &i:arr1){
		cin >> i;
	}
	for(int &i:arr2){
		cin >> i;
	}
	vi solution;
	int i,j;
	for(i=0,j=0;i<n && j <m;){
		if(arr1[i] == 0){
			solution.push_back(arr1[i++]);
			lines++;
		}else if(arr2[j] == 0){
			solution.push_back(arr2[j++]);
			lines++;
		}else if(arr1[i] <= lines){
			solution.push_back(arr1[i++]);
		}else if(arr2[j] <= lines){
			solution.push_back(arr2[j++]);
		}else{
			cout<<"-1\n";
			return;
		}
	}
	for(;i<n;i++){
		if(arr1[i] == 0){
			solution.push_back(arr1[i]);
			lines++;
		}else if(arr1[i] <= lines){
			solution.push_back(arr1[i]);
		}else{
			cout<<"-1\n";
			return;
		}
	}
	for(;j<m;j++){
		if(arr2[j] == 0){
			solution.push_back(arr2[j]);
			lines++;
		}else if(arr2[j] <= lines){
			solution.push_back(arr2[j]);
		}else{
			cout<<"-1\n";
			return;
		}
	}
	for(int x:solution){
		cout<<x<<" ";
	}
	cout<<"\n";
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