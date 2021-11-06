#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,x;
		cin>>n>>x;
		ll sum = 0;
		vector<ll> arr(n);
		bool flag = false;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
			if(arr[i]%x!=0){
				flag = true;
			}
		}
		if(!flag){
			cout<<-1<<"\n";
		}else if(sum%x!=0){
			cout<<n<<"\n";
		}else{
			int first = n-1,last = 0;
			for(int i=0;i<n;i++){
				if(arr[i]%x!=0){
					first = i;
					break;
				}
			}
			for(int i=n-1;i>=0;i--){
				if(arr[i]%x!=0){
					last = i;
					break;
				}
			}
			cout<<(n - min(first + 1,n - last))<<endl;
		}
	}
	return 0;
}