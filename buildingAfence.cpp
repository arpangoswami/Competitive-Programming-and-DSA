#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;

void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int &i:arr){
		cin >> i;
	}
	bool f = true;
	int low1 = arr[0],low2 = arr[0] + k,high1 = arr[0],high2 = arr[0] + k;
	for(int i=1;i<(n-1);i++){
		int highH = arr[i] + k + k-1,highL = arr[i] + k-1,lowH = arr[i] + k,lowL = arr[i];
		if(high1 >= highH){

		}else{

		}
		if(low2 <= lowL){

		}else{

		}
		
		if(f){
			cout<<"NO"<<'\n';
			return;
		}
	}
	int rangeMin = arr[n-1],rangeMax = arr[n-1] + k;
	if(low2 <= rangeMin && high1 >= rangeMax){
		cout<<"NO"<<'\n';
	}else{
		cout<<"YES"<<'\n';
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