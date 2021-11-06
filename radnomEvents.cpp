#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,double> pii;
void solveQuestion(){
	int n,q;
	cin >> n >> q;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	vector<pii> query(q);
	for(int i=0;i<q;i++){
		cin >> query[i].first >> query[i].second;
	}
	vector<int> arr2(n);
	for(int i=0;i<n;i++){
		arr2[i] = arr[i];
	}
	sort(arr2.begin(),arr2.end());
	int incPrefix = n;
	for(int i=n-1;i>=0;i--){
		if(arr2[i] != arr[i]){
			break;
		}else{
			incPrefix--;
		}
	}
	if(incPrefix == 0){
		cout<<"1.000000"<<'\n';
		return;
	}
	double incorrect = 1.00,correct = 0.00;
	for(int i=0;i<q;i++){
		if(query[i].first >= incPrefix){ 
			double sub = (incorrect * query[i].second);
			correct += sub;
			incorrect -= sub;
		}
	}
	cout<<fixed<<setprecision(6)<<correct<<'\n';
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