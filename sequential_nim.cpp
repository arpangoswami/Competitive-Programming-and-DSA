#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		int cnt = 0;
		for(int i=0;i<(n-1) && arr[i] == 1;i++){
			cnt++;
		}
		if(cnt%2 == 0){
			cout << "First" <<"\n";
		}else{
			cout<<"Second"<<"\n";
		}
	}
	return 0;
}