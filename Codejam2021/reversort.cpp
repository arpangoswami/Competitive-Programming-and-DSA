#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
void reverse(vector<int> &arr,int i,int j){
	while(i < j){
		swap(arr[i++],arr[j--]);
	}
}
void solveQ(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	auto minIdx = [&](int start,int finish){
		int minm = arr[start],ans = start;
		for(int i=start+1;i<=finish;i++){
			if(arr[i] < minm){
				minm = arr[i];
				ans = i;
			}
		}
		return ans;
	};
	int ans = 0;
	for(int i=1;i<=(n-1);i++){
		int setIdx = i-1;
		int idx = minIdx(setIdx,n-1);
		ans += (idx - setIdx + 1);
		reverse(arr,setIdx,idx);
	}
	cout << ans << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveQ();
	}
	return 0;
}