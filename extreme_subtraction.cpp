#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int cnt1 = 0,cnt2 = 0;
	for(int i=1;i<n;i++){
		cnt1 += max(arr[i-1] - arr[i],0LL);
	}
	for(int i=n-2;i>=0;i--){
		cnt2 += max(arr[i+1] - arr[i],0LL);
	}
	if(cnt1 > arr[0] || cnt2 > arr[n-1]){
		cout<<"NO"<<"\n";
	}else{
		cout<<"YES"<<"\n";
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