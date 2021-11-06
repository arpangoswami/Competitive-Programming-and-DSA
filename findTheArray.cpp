#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
		int val = arr[i];
		for(int j=1;j<=30;j++){
			if((1LL<<j) >= val){
				int x = (1LL << j);
				int y = (1LL << (j-1));
				if(x - arr[i] < arr[i] - y){
					if(j == 30){
						arr[i] = (1LL << 29);
					}else{
						arr[i] = x;
					}
				}else{
					arr[i] = y;
				}
				break;
			}
		}
	}
	for(int x:arr){
		cout<<x<<" ";
	}
	cout<<'\n';
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