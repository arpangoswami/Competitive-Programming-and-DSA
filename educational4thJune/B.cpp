#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQ(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	vi temp;
	for(int x:arr){
		if(x%2 == 0){
			temp.push_back(x);
		}
	}
	for(int x:arr){
		if(x&1){
			temp.push_back(x);
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(__gcd(temp[i],2*temp[j]) > 1){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	int tt;
	cin >> tt;
	while(tt-- > 0){
		solveQ();
	}
	return 0;
}