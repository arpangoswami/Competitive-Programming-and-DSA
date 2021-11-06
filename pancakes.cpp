#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	vi pancake(n+1);
	for(int &i:arr){
		cin >> i;
	}
	for(int i=0;i<n;i++){
		if(arr[i] > 0){
			int low = max(i-arr[i] + 1,0LL);
			pancake[i+1]--;
			pancake[low]++;
		}
	}
	for(int i=1;i<n;i++){
		pancake[i] += pancake[i-1];
	}
	for(int i=0;i<n;i++){
		if(pancake[i] > 0){
			cout<<1<<" ";
		}else{
			cout<<0<<" ";
		}
	}
	cout<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}