#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	int cnt0 = 0,cnt1 = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		if(arr[i]){
			cnt1++;
		}else{
			cnt0++;
		}
	}
	if(cnt0>=n/2){
		cout<<cnt0<<"\n";
		for(int i=0;i<cnt0;i++){
			cout<<0<<" ";
		}
		cout<<"\n";
	}else{
		if(cnt1 % 2 == 0){
			cout<<cnt1<<"\n";
			for(int i=0;i<cnt1;i++){ 
				cout<<1<<" ";
			}
			cout<<"\n";
		}else{
			cout<<cnt1-1<<"\n";
			for(int i=1;i<cnt1;i++){
				cout<<1<<" ";
			}
			cout<<"\n";
		}
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