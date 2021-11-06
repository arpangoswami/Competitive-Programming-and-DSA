#include <bits/stdc++.h>
#define int long long 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	for(int x:arr){
		if(x < 0){
			cout<<"NO\n";
			return;
		}
	}
	int g = 0;
	for(int i=0;i<n;i++){
		g = __gcd(g,arr[i]);
	}
	int maxm = *max_element(arr.begin(),arr.end()),minm = *min_element(arr.begin(),arr.end());
	if(maxm/g > 300){
		cout<<"NO\n";
	}else if(maxm/g == 300 && minm == 0){
		cout<<"NO\n";
	}else{
		cout<<"YES\n";
		if(minm == 0){
			cout<<(maxm/g)+1<<"\n";
			cout<<0<<" ";
		}else{
			cout<<(maxm/g)<<"\n";
		}
		int div = maxm/g;
		for(int i=1;i<=div;i++){
			cout<<i*g<<" ";
		}
		cout<<"\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	int tt;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}