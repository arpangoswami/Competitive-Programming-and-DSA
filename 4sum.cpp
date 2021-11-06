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
	for(int i=0;i<(n-3);i++){
		for(int j=i+1;j<(n-2);j++){
			int low = j+1,high = n-1;
			int req = sum - arr[i].first - arr[j].first;
			while(low < high){
				if(arr[low].first + arr[high].first == req){
					cout<<arr[i].second + 1 <<" "<<arr[j].second + 1<<" "<<arr[low].second + 1<<" "<<arr[high].second+1<<"\n";
					return;
				}else if(arr[low].first + arr[high].first > req){
					high--;
				}else{
					low++;
				}
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