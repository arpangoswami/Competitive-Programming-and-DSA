#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	int cumXor = 0,maxm = 0,maxIdx = -1;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		cumXor ^= arr[i];
		if(arr[i] >= maxm){
			maxIdx = i;
			maxm = arr[i];
		}
	}
	if(cumXor == 0){
		cout<<"No winning move"<<"\n";
		return;
	}
	cumXor ^= arr[maxIdx];
	for(int i=maxm;i>=1;i--){
		if(cumXor ^ (maxm - i) == 0){
			cout<<"Move "<<i<<" matchstick from matchbox "<<(maxIdx+1)<<"\n";
			return;
		}
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