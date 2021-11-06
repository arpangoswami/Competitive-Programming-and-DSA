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
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	vi even;
	vi odd;
	for(int i=0;i<n;i+=2){
		even.push_back(arr[i]);
	}
	for(int i=1;i<n;i+=2){
		odd.push_back(arr[i]);
	}
	sort(even.begin(),even.end());
	sort(odd.begin(),odd.end());
	sort(arr.begin(),arr.end());
	int j = 0,k = 0;
	for(int i=0;i<n;i+=2){
		if(n&1 && i == n-1){
			if(arr.back() != even.back()){
				cout<<"NO\n";
				return;
			}else{
				cout<<"YES\n";
				return;
			}
		}
		if(arr[i] != even[j] || arr[i+1] != odd[k]){
			cout<<"NO\n";
			return;
		}
		//cout<<arr[i]<<" "<<arr[i+1]<<" "<<odd[k]<<" "<<even[j]<<"\n";
		j++;
		k++;
	}
	cout<<"YES\n";
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