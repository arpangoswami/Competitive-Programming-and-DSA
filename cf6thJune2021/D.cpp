#include <bits/stdc++.h>
#define int long long 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	set<int> st;
	int prev = 0;
	for(int i:arr){
		if(st.empty()){
			st.insert(i);
			prev = i;
			continue;
		}
		if(prev == i){
			continue;
		}
		int small = min(prev,i);
		int big = max(prev,i);
		st.insert(i);
		if(*st.upper_bound(small) != big){
			cout<<"NO\n";
			return;
		}
		prev = i;
	}
	cout<<"YES\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	int tt;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}