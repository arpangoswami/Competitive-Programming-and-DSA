#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,sum;
	cin >> n >> sum;
	vector<pii> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<(n-2);i++){
		int req = sum - arr[i].first;
		int low = i+1,high = n-1;
		while(low < high){
			if(arr[low].first + arr[high].first == req){
				cout<<arr[low].second + 1<<" "<<arr[i].second + 1<<" "<<arr[high].second + 1<<"\n";
				return;
			}else if(arr[low].first + arr[high].first > req){
				high--;
			}else{
				low++;
			}
		}
	}
	cout<<"IMPOSSIBLE"<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}