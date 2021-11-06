#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	string s;
	cin >> s;
	stack<int> st;
	st.push(-1);
	int n = s.size();
	int max_len = 0,max_count = 1;
	for(int i=0;i<n;i++){
		if(s[i] == '('){
			st.push(i);
		}else{
			st.pop();
			if(st.empty()){
				st.push(i);
			}else{
				int curr_len = i - st.top();
				if(curr_len == max_len){
					max_count++;
				}else if(max_len < curr_len){
					max_len = curr_len;
					max_count = 1;
				}
			}
		}
	}
	cout<<max_len<<" "<<max_count;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}