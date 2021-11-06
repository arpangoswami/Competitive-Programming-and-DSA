#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool equals(vector<int> &sorted,vector<int> &arr){
	int n = sorted.size();
	for(int i=0;i<n;i++){
		if(sorted[i] != arr[i]){
			return false;
		}
	}
	return true;
}
void operation(vector<int> &sorted,vector<int> &arr,int op){
	if(op == 0){
		int n = sorted.size();
		for(int i=0;i<=(n-2);i+=2){
			swap(sorted[i],sorted[i+1]);
		}
	}else{
		int twice = sorted.size();
		int n = twice/2;
		for(int i=0;i<n;i++){ 
			swap(sorted[i],sorted[(i+n)]);
		}
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(2*n);
	for(int &i:arr){
		cin >> i;
	}
	vi sorted(2*n);
	for(int i=0;i<2*n;i++){
		sorted[i] = (i+1);
	}
	int ans = 2*n;
	//12121212
	int curr = 0;
	int op = 1;
	while(!equals(sorted,arr) && curr < ans){
		curr++;
		operation(sorted,arr,op);
		// cout<<"HERE"<<'\n';
		// for(int x:sorted){
		// 	cout<<x<<" ";
		// }
		//cout<<'\n';
		op ^= 1;
	}
	//cout<<"curr: "<<curr<<'\n';
	ans = min(ans,curr);
	//21212121
	curr = 0;
	op = 0;
	for(int i=0;i<2*n;i++){
		sorted[i] = (i+1);
	}
	while(!equals(sorted,arr) && curr < ans){
		curr++;
		operation(sorted,arr,op);
		// cout<<"THERE"<<'\n';
		// for(int x:sorted){
		// 	cout<<x<<" ";
		// }
		// cout<<'\n';
		op ^= 1;
	}
	ans = min(ans,curr);
	if(ans >= 2*n){
		cout<<-1;
		return;
	}
	cout<<ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}