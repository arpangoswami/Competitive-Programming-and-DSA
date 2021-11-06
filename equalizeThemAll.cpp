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
const int maxNum = 200000;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n+1);
	vi freq(maxNum+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		freq[arr[i]]++;
	}
	int maxFreq = 1,num = arr[1];
	for(int i=0;i<=maxNum;i++){
		if(freq[i] > maxFreq){
			maxFreq = freq[i];
			num = i;
		}
	}
	vector<int> indices;
	for(int i=1;i<=n;i++){
		if(arr[i] == num){
			indices.push_back(i);
		}
	}
	cout<<n-maxFreq<<"\n";
	for(int j=0;j<maxFreq;j++){
		int leftMost = 1;
		if(j > 0){
			leftMost = indices[j-1]+1;
		}
		for(int i=(indices[j]-1);i>=leftMost;i--){
			if(arr[i] > num){
				cout<<"2 "<<i<<" "<<(i+1)<<"\n";
			}else if(arr[i] < num){
				cout<<"1 "<<i<<" "<<(i+1)<<"\n";
			}
		}
	}
	int rightMost = n;
	for(int i=(indices.back()+1);i<=n;i++){
		if(arr[i] > num){
			cout<<"2 "<<i<<" "<<(i-1)<<"\n";
		}else if(arr[i] < num){
			cout<<"1 "<<i<<" "<<(i-1)<<"\n";
		}
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}