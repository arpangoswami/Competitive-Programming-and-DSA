#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &x:arr){
		cin >> x;
	}
	int maxm = *max_element(arr.begin(),arr.end());
	int sMax = 0,mxId = -1;
	for(int i=0;i<n;i++){
		if(arr[i] > sMax && arr[i] < maxm){
			sMax = arr[i];
			mxId = i;
		}
	}
	cout << mxId + 1;
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}