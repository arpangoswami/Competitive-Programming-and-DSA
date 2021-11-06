#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<ll> arr(n);
	for(int i=0;i<n;i++) cin >> arr[i];
	vector<ll> tail;
	tail.push_back(arr[0]);
	for(int i=1;i<n;i++){
		if(arr[i] > tail.back()){
			tail.push_back(arr[i]);
		}else{
			int idx = lower_bound(tail.begin(),tail.end(),arr[i]) - tail.begin();
			tail[idx] = arr[i];
		}
	}
	cout<<tail.size()<<endl;
	return 0;
}