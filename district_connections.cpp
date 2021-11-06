#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	bool allSame = true;
	int firstVal = arr[0],firstIdx = 1,secondIdx = -1;
	for(int i=1;i<n;i++){
		if(arr[i] != arr[i-1]){
			allSame = false;
			secondIdx = i+1;
			break;
		}
	}
	if(allSame){
		cout<<"NO"<<"\n";
	}else{
		cout<<"YES"<<"\n";
		vector<int> v;
		for(int i=1;i<n;i++){
			if(arr[i] == firstVal){
				v.push_back(i+1);
			}else{
				cout<<1<<" "<<(i+1)<<"\n";
			}
		}
		for(int x:v){
			cout<<secondIdx<<" "<<x<<"\n";
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