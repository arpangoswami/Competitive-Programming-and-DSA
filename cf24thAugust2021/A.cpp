#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
void iteration(int sidx,vector<int> &arr){
	for(int i=sidx;i<arr.size();i+=2){
		if(i < ((int)arr.size() - 1) && arr[i] > arr[i+1]){
			swap(arr[i],arr[i+1]);
		}
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &x:arr){
		cin >> x;
	}
	vi copy = arr;
	sort(copy.begin(),copy.end());
	int ans = 0;
	while(copy != arr){
		ans++;
		if(ans & 1){
			iteration(0,arr);
		}else{
			iteration(1,arr);
		}
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}