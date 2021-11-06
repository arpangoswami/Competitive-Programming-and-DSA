#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(i%2 == 0){
				if(arr[i] < 0){
					arr[i] = -arr[i];
				}
			}else{
				if(arr[i] > 0){
					arr[i] = -arr[i];
				}
			}
		}
		for(int x:arr){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	return 0;
}