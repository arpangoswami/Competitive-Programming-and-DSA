#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		int ans = 0;
		int n,k;
		cin>>n>>k;
		vector<int> arr(n);
		for(int i=0;i<n;++i){
			cin>>arr[i];
		}
		int idx = 0;
		while(idx<n){
			if(arr[idx] == k){
				bool flag = true;
				int temp = k-1,i = idx+1;
				for(i=idx+1;i<n && arr[i] == temp;i++){
					temp--;
				}
				if(temp == 0){
					ans++;
				}
				idx = i;
			}
			else
				idx++;	
		}
		cout<<"Case #"<<t<<":"<<" "<<ans<<"\n";
	}
	return 0;
}