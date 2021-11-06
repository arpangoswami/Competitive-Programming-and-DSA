#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N = 11;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int maxIdxTillNow = 0;
	for(int bit = N;bit>=0;bit--){
		int maxInd = maxIdxTillNow;
		int maxm = -1;
		for(int j=maxIdxTillNow;j<n;j++){
			if(((arr[j] >> bit) & 1) == 1 && arr[j] > maxm){
				maxm = arr[j];
				maxInd = j;
			}
		}
		if(maxm != -1){
			swap(arr[maxIdxTillNow],arr[maxInd]);
			maxInd = maxIdxTillNow;
			for(int j=0;j<n;j++){
				if(j == maxInd){
					continue;
				}
				if((arr[j] >> bit) & 1){
					arr[j] = arr[j] ^ arr[maxInd];
				}
			}
			maxIdxTillNow++;
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		ans ^= arr[i];
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}