
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int cnt = 0;
int ask(vi &arr,int i){
	if(arr[i] != 0){
		return arr[i];
	}
	cout<<"? "<<i<<endl;
	cout.flush();
	int val;
	cin >> val;
	arr[i] = val;
	return val;
}
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n+2);
	arr[0] = 1e9;
	arr[n+1] = 1e9;
	if(n == 1){
		cout<<"! "<<1<<'\n';
		return;
	}
	int low = 1,high = n;
	while(low <= high){
		int mid = (low+high)/2;
		int v2 = ask(arr,mid),v1 = ask(arr,mid-1),v3 = ask(arr,mid+1);
		if(v2 < min(v1,v3)){
			cout<<"! "<<mid<<endl;
			cout.flush();
			return;
		}
		if(v1 < v3){
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	while(test--){
		solveQuestion();
	}
	return 0;
}
