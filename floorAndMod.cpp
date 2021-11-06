#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int binSearch(int a,int b,int cont){
	int low = 1,high = b,ans = 1;
	while(low <= high){
		int mid = (low + high)/2;
		if((mid + 1) * cont <= a){
			ans = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	return ans;
}
void solveQuestion(){
	int x,y;
	cin >> x >> y;
	int maxCheck = floor(sqrt(x));
	int ans = 0;
	for(int i=1;i<=maxCheck;i++){
		int right = binSearch(x,y,i);
		int cont = (right-i);
		if(cont <= 0){
			break;
		}
		ans += cont;
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