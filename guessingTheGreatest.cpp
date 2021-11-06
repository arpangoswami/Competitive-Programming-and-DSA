#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
map<pii,int> mp;
int askQuery(int low,int high){
	if(low >= high){
		return -1;
	}
	if(mp.count({low,high})){
		return mp[{low,high}];
	}
	cout<<"? "<<low+1<<" "<<high+1<<endl;
	int x;
	cin >> x;
	return mp[{low,high}] = x-1;
}
void solveQuestion(){
	int n;
	cin >> n;
	int low = 0,high = n;
	while(low + 1 < high){
		int mid = (low + high)/2;
		int smax = askQuery(low,high-1);
		if(smax < mid){
			if(askQuery(low,mid-1) == smax){
				high = mid;
			}else{
				low = mid;
			}
		}else{	
			if(askQuery(mid,high-1) == smax){
				low = mid;
			}else{
				high = mid;
			}
		}
	}
	cout << "! "<<high;
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