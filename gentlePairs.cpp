#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<pii> arr(n);
	int cnt = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i].first >> arr[i].second;
	}
	for(int i=0;i<(n-1);i++){
		for(int j=i+1;j<n;j++){
			if(arr[i].first == arr[j].first){
				continue;
			}
			double slope = (double)(arr[j].second - arr[i].second) / (double)(arr[j].first - arr[i].first);
			if(slope >= -1.00 && slope <= 1.00){
				cnt++;
			}
		}
	}
	cout<<cnt<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}