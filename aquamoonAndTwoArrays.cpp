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
	vi arr1(n),arr2(n),deplet,excess;
	int s1 = 0,s2 = 0;
	for(int &x:arr1){
		cin >> x;
		s1 += x;
	}
	for(int i=0;i<n;i++){
		cin >> arr2[i];
		s2 += arr2[i];
		if(arr2[i] > arr1[i]){
			deplet.push_back(i);
		}else if(arr2[i] < arr1[i]){
			excess.push_back(i);
		}
	}
	if(s1 != s2){
		cout<<"-1\n";
		return;
	}
	vector<pii> sol;
	int ptr = 0;
	for(int i=0;i<excess.size();i++){
		int id1 = excess[i];
		while(arr1[id1] > arr2[id1]){
			int id2 = deplet[ptr];
			while(arr1[id1] > arr2[id1] && arr1[id2] < arr2[id2]){
				sol.push_back({id1,id2});
				arr1[id1]--;
				arr1[id2]++;
			}
			if(arr2[id2] == arr1[id2]){
				ptr++;
			}
		}
	}
	cout << sol.size() << "\n";
	for(auto x:sol){
		cout<<x.ff+1<<" "<<x.ss+1<<"\n";
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