#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool askQuery(int i,int j){
	string ans;
	cout<<"? "<<(i+1)<<" "<<(j+1)<<endl;
	cin >> ans;
	if(ans == "Yes"){
		cout<<"! "<<(i+1)<<" "<<(j+1)<<endl;
		return true;
	}
	return false;
}
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	vector<array<int,4>> ar;
	int ptr = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ar.push_back({arr[i],arr[j],i,j});
		}
	}
	for(auto &x:ar){
		if(x[0] > x[1]){
			swap(x[0],x[1]);
			swap(x[2],x[3]);
		}
	}
	sort(ar.begin(),ar.end(),[](auto &v1,auto &v2){
		return (v1[1]-v1[0]) > (v2[1] - v2[0]);
	});
	for(auto x:ar){
		bool f = askQuery(x[3],x[2]);
		if(f){
			return;
		}
	}
	cout<<"! "<<0<<" "<<0<<endl;
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