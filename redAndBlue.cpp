#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr1(n);
	for(int i=0;i<n;i++){
		cin >> arr1[i];
	}
	int m;
	cin >> m;
	vector<int> arr2(m);
	for(int i=0;i<m;i++){
		cin >> arr2[i];
	}
	int maxPref1 = 0,maxPref2 = 0,curr1 = 0,curr2 = 0;
	for(int x:arr1){
		curr1 += x;
		maxPref1 = max(maxPref1,curr1);
	}
	for(int x:arr2){
		curr2 += x;
		maxPref2 = max(maxPref2,curr2);
	}
	//cout<<"maxPref1: "<<maxPref1<<" maxPref2: "<<maxPref2<<'\n';
	cout<<maxPref1+maxPref2<<'\n';
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