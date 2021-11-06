#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	unordered_set<int> st;
	for(int x:arr){
		st.insert(x);
	}
	int num = st.size();
	if(k == 1 && num > 1){
		cout<<-1<<"\n";
		return;
	}
	if(num <= k){
		cout<<1<<"\n";
		return;
	}
	cout << ceil((double) (num-1)/ (double)(k-1))<<"\n"; 
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