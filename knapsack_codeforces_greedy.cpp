#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,w;
	cin >> n >> w;
	int req = (w + 1)/2;
	vector<pii> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}	
	sort(arr.begin(),arr.end(),greater<pii>());
	int picked = 0;
	vector<int> sol;
	for(int i=0;i<n && picked < req;i++){
		if(picked + arr[i].first > w){
			continue;
		}else{
			picked += arr[i].first;
			sol.push_back(arr[i].second + 1);
		}
	}
	if(picked < req){
		cout<<-1<<"\n";
		return;
	}
	cout<<sol.size()<<"\n";
	for(int x:sol){
		cout<<x<<" ";
	}
	cout<<"\n";
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