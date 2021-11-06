#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,sum;
	cin>>n>>sum;
	vector<int>coins(n);
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	vector<int>arr(sum+1,1e9);
	arr[0] = 0;
	for(int i=1;i<=sum;i++){
		for(int j=0;j<n;j++){
			if(i>=coins[j]){
				arr[i] = min(arr[i],1+arr[i - coins[j]]);
			}
		}
	}
	if(arr[sum]>=1e9){
		cout<<-1<<endl;
	}else{
		cout<<arr[sum]<<endl;
	}
	return 0;
}