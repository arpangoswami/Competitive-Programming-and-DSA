#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	int maxm = 0,maxIdx = -1,sum = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		if(arr[i] > maxm){
			maxIdx = i;
			maxm = arr[i];
		}
		sum += arr[i];
	}
	int def = 0;
	for(int i=0;i<n;i++){
		def += (maxm - arr[i]);
	}
	if(def < maxm){
		if(sum % (n-1) == 0){
			cout<<0<<'\n';
		}else{
			int nVal = (((sum)/(n-1))*(n-1) + (n-1));
			cout<<(nVal - sum)<<'\n';
		}
	}else{
		cout << (maxm * (n-1) - sum) <<'\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}