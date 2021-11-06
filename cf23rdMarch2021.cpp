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
	priority_queue<int> pq(arr.begin(),arr.end());
	vector<int> sol(n);
	vector<bool> picked(n+1,false);
	int j = n-1,i = 0;
	while(!pq.empty()){
		int t = pq.top();
		pq.pop();
		if(picked[t]){
			continue;
		}
		stack<int> st;
		while(j >= 0){
			picked[arr[j]] = true;
			st.push(arr[j]);
			j--;
			if(st.top() == t){
				break;
			}
		}
		while(!st.empty()){
			sol[i++] = st.top();
			st.pop();
		}
	}
	for(int x:sol){
		cout<<x<<" ";
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