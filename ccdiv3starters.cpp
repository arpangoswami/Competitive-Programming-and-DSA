#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
inline int calSum(vector<vector<int>> &pref,int tlx,int tly,int brx,int bry){
	int add1 = pref[brx][bry];
	int add2 = (tlx > 0 && tly > 0) ? pref[tlx-1][tly-1] : 0;
	int sub1 = (tlx > 0) ? pref[tlx-1][bry] : 0;
	int sub2 = (tly > 0) ? pref[brx][tly-1] : 0;
	return add1 + add2 - sub1 - sub2;
}
bool check(vector<vector<int>> &pref,int squareSize,int oneCnt,int m,int n,int k){
	if(squareSize * squareSize > oneCnt){
		return false;
	}
	//cout<<"squareSize: "<<squareSize<<" oneCnt: "<<oneCnt<<" m: "<<m<<" n: "<<n<<" k: "<<k<<'\n';
	for(int i=0;i<=(m-squareSize);i++){
		for(int j=0;j<=(n-squareSize);j++){
			int tlx = i,tly = j,brx = i+squareSize-1,bry = j+squareSize-1;
			int sum = calSum(pref,tlx,tly,brx,bry);
			int remOnes = oneCnt - sum;
			int reqOnes = squareSize * squareSize - sum;
			if(reqOnes <= min(k,remOnes)){
				return true;
			}
		}
	}
	return false;
}
int squareRoot(int n){
	int low = 1,high = n;
	int ans = low;
	while(low <= high){
		int mid = (low + high)/2;
		if(mid * mid <= n){
			ans = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	return ans;
}
void solveQuestion(){
	int m,n,k;
	cin >> m >> n >> k;
	vector<string> input(m);
	for(string &s:input){
		cin >> s;
	}
	int ones = 0;
	vector<vector<int>> arr(m,vector<int>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(input[i][j] == '1'){
				arr[i][j] = 0;
			}else{
				arr[i][j] = 1;
				ones++;
			}
		}
	}
	if(ones < 1){
		cout<<0<<'\n';
		return;
	}
	vector<vector<int>> pref(m,vector<int>(n));
	pref[0][0] = arr[0][0];
	for(int j=1;j<n;j++){
		pref[0][j] = pref[0][j-1] + arr[0][j];
	}
	for(int i=1;i<m;i++){
		pref[i][0] = pref[i-1][0] + arr[i][0];
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + arr[i][j];
		}
	}
	int low = 1,ans = low;
	int high = squareRoot(ones);
	high = min(high,min(m,n));
	while(low <= high){
		int mid = (low + high)/2;
		if(check(pref,mid,ones,m,n,k)){
			ans = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	cout<<ans<<'\n';
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