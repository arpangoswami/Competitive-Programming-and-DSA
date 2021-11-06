#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		int n;
		cin >> n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}	
		stack<int>st;
		st.push(0);
		int span[n];
		span[0] = 1;
		for(int i=1;i<n;i++){
			while(!st.empty() && arr[i]>=arr[st.top()]){
				st.pop();
			}
			if(st.empty()){
				span[i] = i+1;
			}else{
				span[i] = i-st.top();
			}
			st.push(i);
		}
		for(int i=0;i<n;i++){
			cout<<span[i]<<" ";
		}
		cout<<"END";
	}
	return 0;
}