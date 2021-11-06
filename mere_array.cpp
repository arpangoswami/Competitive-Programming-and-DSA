#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n),arr2(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		arr2[i] = arr[i];
	}
	sort(arr2.begin(),arr2.end());
	bool alreadySorted = true;
	for(int i=0;i<n;i++){
		if(arr2[i]!=arr[i]){
			alreadySorted = false;
			break;
		}
	}
	if(alreadySorted){
		cout<<"YES"<<"\n";
	}else{
		int minm = arr2[0];
		bool f =  true;
		for(int i=0;i<n;i++){
			if(arr2[i]!=arr[i] && arr[i]%minm!=0){
				f = false;
				break;
			}
		}
		string ans = f ? "YES" : "NO";
		cout<<ans<<"\n";
	}
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