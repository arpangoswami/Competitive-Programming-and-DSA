#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,x;
	cin >> n >> x;
	vector<pii> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].first;
		arr[i].second = 1;
	}
	int i = 0;
	bool ok = true;
	while(i < n){
		if(ok && ((arr[i].first) % x == 0)){
			int val = (arr[i].first)/x;
			int freq = (arr[i].second);
			arr.push_back({val,freq*x});
			n++;	
		}else if(ok && (arr[i].first % x) != 0){
			ok = false;
		}
		i++;
	}
	int sum = 0;
	for(pii x:arr){
		sum += (x.first * x.second);
	}
	cout<<sum<<'\n';
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