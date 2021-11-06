#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
int lcm2(int a,int b){
	return (a*b)/__gcd(a,b);
}
int lcm3(int a,int b,int c){
	return lcm2(lcm2(a,b),c);
}
/*
1
3
333333333 333333333 333333333
*/
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &x:arr){
		cin >> x;
	}
	if((n % 2) == 0){
		for(int i=0;i<n;i+=2){
			cout << (arr[i+1] * -1) <<" "<< arr[i] << " ";
		}
	}else{
		int a = arr[0],b = arr[1],c = arr[2];
		if(a != b){
			cout<<-c<<" "<<c<<" "<<(a-b)<<" ";
		}else if(a != c){
			cout<<-b<<" "<<(a-c)<<" "<<b<<" ";
		}else{
			cout<<"1 1 -2 ";
		}
		for(int i=3;i<n;i+=2){
			int g = __gcd(arr[i],arr[i+1]);
			arr[i] /= g;
			arr[i+1]/=g;
			cout << (arr[i+1] * -1) <<" "<< arr[i] << " ";
		}
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