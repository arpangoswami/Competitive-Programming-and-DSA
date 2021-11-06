#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool comp(pii &p1,pii &p2){
	return ((2 * p1.first + p1.second) > (2 * p2.first + p2.second));
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<pii> arr(n);
	int aokiSum = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i].first >> arr[i].second;
		aokiSum += arr[i].first;
	}
	int tokiSum = 0;
	sort(arr.begin(),arr.end(),comp);

	for(int i=0;i<n;i++){
		tokiSum += (arr[i].first + arr[i].second);
		aokiSum -= arr[i].first;
		if(tokiSum > aokiSum){
			cout<<(i+1)<<'\n';
			return;
		}
	}
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