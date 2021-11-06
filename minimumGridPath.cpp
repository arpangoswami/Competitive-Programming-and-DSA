#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> even;
	vector<int> odd;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	int horizontalSteps = n,verticalSteps = n,prefSum = 0,minVer = arr[1],minHor = arr[0],ans = n * (arr[0] + arr[1]);
	// n horizontal steps to take
	// n vertical steps to take
	for(int i=0;i<n;i++){
		prefSum += arr[i];
		if(i % 2 == 1){
			minVer = min(minVer,arr[i]);
			verticalSteps--;
		}else{
			minHor = min(minHor,arr[i]);
			horizontalSteps--;
		}
		ans = min(ans,prefSum + horizontalSteps * minHor + verticalSteps * minVer);
		// will take as many steps as possible on the lowest of them
	}
	cout << ans << '\n';
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