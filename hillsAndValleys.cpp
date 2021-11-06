#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n;
vi arr;
inline bool isMountain(int i){
	return ((i>=1) && (i<(n-1)) && arr[i] > arr[i-1] && arr[i] > arr[i+1]);
}
inline bool isValley(int i){
	return ((i>=1) && (i<(n-1)) && arr[i] < arr[i-1] && arr[i] < arr[i+1]);
}
void solveQuestion(){
	cin >> n;
	arr.resize(n);
	for(int &i:arr){
		cin >> i;
	}
	vi hillOrValley(n);
	int ans = 0;
	for(int i=1;i<(n-1);i++){
		if(isValley(i) || isMountain(i)){
			ans++;
			hillOrValley[i] = 1;
		}
	}
	int original = ans;
	for(int i=1;i<n-1;i++){
		int temp = arr[i];
		arr[i] = arr[i-1];
		ans = min(ans,original - hillOrValley[i] - hillOrValley[i-1] - hillOrValley[i+1] + isMountain(i-1) + isValley(i-1) + isMountain(i) + isValley(i) + isMountain(i+1) + isValley(i+1));
		arr[i] = arr[i+1];
		ans = min(ans,original - hillOrValley[i] - hillOrValley[i-1] - hillOrValley[i+1] + isMountain(i-1) + isValley(i-1) + isMountain(i) + isValley(i) + isMountain(i+1) + isValley(i+1));
		arr[i] = temp;
	}
	
	cout<<ans<<'\n';
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