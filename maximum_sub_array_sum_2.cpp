#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,a,b;
	cin>>n>>a>>b;
	array<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	array<int> prefix(n+1,0);
	for(int i=1;i<=n;i++){
		prefix[i] = prefix[i-1] + arr[i-1];
	}
	ll max_sum = prefix[a],curr_sum = prefix[a];
	for(int i=a-1;i<n;){
		int curr_len = a;
		ll threshold = curr_sum = prefix[i+1] - prefix[i+1-a];
		int endIdx = i;
		while(curr_len <= b){
			
		}
		max_sum = max(max_sum,curr_sum);
		i = endIdx+1;
	}
	cout<<max_sum<<"\n";
	return 0;
}