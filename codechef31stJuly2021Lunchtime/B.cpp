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
vector<int> rotateMin(vector<int> &arr,int index,int n){
	vector<int> sol(n);
	int ptr = 0;
	for(int i=index;i<n;i++){
		sol[ptr++] = arr[i];
	}
	for(int i=0;i<index;i++){
		sol[ptr++] = arr[i];
	}
	return sol;
}
vector<int> modify(vector<int> &A,vector<int> &B,int n){
	vector<int> sol(n);
	for(int i=0;i<n;i++){
		sol[i] = (A[i] + B[i])%n;
	}
	return sol;
}
void solveQuestion(){
	int n;
	cin >> n;
	vi A(n);
	for(int &x:A){
		cin >> x;
	}
	vi B(n);
	for(int &x:B){
		cin >> x;
	}
	int minMod = n;
	for(int i=0;i<n;i++){
		minMod = min((A[0] + B[i])%n,minMod);
	}
	int ind1 = -1,ind2 = -1;
	for(int i=0;i<n;i++){
		if(((A[0] + B[i]) % n) == minMod){
			if(ind1 == -1){
				ind1 = i;
			}else{
				ind2 = i;
			}
		}
	}
	vector<int> sol1 = rotateMin(B,ind1,n);
	vector<int> ans1 = modify(A,sol1,n);
	if(ind2 != -1){
		vector<int> sol2 = rotateMin(B,ind2,n);
		vector<int> ans2 = modify(A,sol2,n);
		bool f = true;
		for(int i=0;i<n;i++){
			if(ans2[i] < ans1[i]){
				f = false;
				break;
			}else if(ans1[i] < ans2[i]){
				break;
			}
		}
		if(f){
			for(int i=0;i<n;i++){
				cout<<ans1[i]<<" ";
			}
		}else{
			for(int i=0;i<n;i++){
				cout<<ans2[i]<<" ";
			}
		}
		cout<<"\n";
		return;
	}
	for(int i=0;i<n;i++){
		cout<<ans1[i]<<" ";
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