#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int left,right;
	cin >> left >> right;
	if(left == 1){
		cout<<((right) * (right + 1))/2<<"\n";
	}else{
		unordered_set<int> st;
		st.insert(0);
		for(int i=left;i<=right;i++){
			for(int x:st){
				st.insert(x+i);
			}
		}
		cout<<((st.size())-1)<<"\n";
	}	
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}