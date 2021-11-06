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
	int n,k;
	cin >> n >> k;
	vi arr(n);
	map<int,vector<int>> indices;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		indices[arr[i]].push_back(i);
	}
	vector<int> solution(n);
	vector<int> temp;
	for(auto it:indices){
		if((it.second).size() >= k){
			vector<int> &ind = it.second;
			for(int i=0;i<k;i++){
				solution[ind[i]] = i+1;
			}
		}else{
			int frq = (it.second).size();
			vector<int> &ind = it.second;
			int cnt = 0;
			while(cnt < frq && temp.size() < k){
				temp.push_back(ind[cnt++]);
			}
			if(temp.size() == k){
				for(int i=0;i<k;i++){
					solution[temp[i]] = i+1;
				}
				// for(int x:temp){
				// 	cout<<"ye: "<<x<<" ";
				// }
				// cout<<"\n";
				temp.clear();
				for(int i=cnt;i<frq;i++){
					temp.push_back(ind[i]);
				}
			}
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