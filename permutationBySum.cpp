#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,l,r,s;
	cin >> n >> l >> r >> s;
	int sz = r-l+1;
	int lSum = (sz*(sz+1))/2,rSum = (n*(n+1))/2 - ((n-sz)*(n-sz+1))/2;
	if(s < lSum || s > rSum){
		cout<<-1<<'\n';
		return;
	}
	set<int> st;
	for(int i=1;i<=n;i++){
		st.insert(i);
	}
	vi arr(n+1);
	vi temp(n+1);
	for(int i=l;i<=r;i++){
		temp[i] = temp[i-1]+(i-l+1);
	}
	for(int i=r;i>=l;i--){
		int rem = s-temp[i-1];
		auto it = st.lower_bound(rem);
		if(it == st.end() || *it > rem){
			--it;
		}
		arr[i] = *it;
		st.erase(it);
		s -= arr[i];
	}
	for(int i=1;i<=n;i++){
		if(arr[i] == 0){
			arr[i] = *st.begin();
			st.erase(arr[i]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
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