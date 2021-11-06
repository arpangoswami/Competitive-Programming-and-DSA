#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n+2);
	for(int &i:arr){
		cin >> i;
	}
	sort(arr.begin(),arr.end());
	int s = 0;
	bool f = false;
	for(int i=0;i<n;i++){
		s += arr[i];
	}
	if(s == arr[n]){
		f = true;
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	s += arr[n];
	for(int i=0;i<=n;i++){
		if(s - arr[i] == arr[n+1]){
			f = true;
			arr[i] = -1;
			break;
		}
	}
	if(!f){
		cout<<-1<<'\n';
	}else{
		for(int i=0;i<=n;i++){
			if(arr[i] != -1){
				cout<<arr[i]<<" ";
			}
		}
		cout<<'\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}