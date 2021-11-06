#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	set<int> st;
	for(int i=1;i<=n;i++){
		st.insert(i);
	}
	cout.flush();
	vector<int> perm(n);
	for(int i=0;i<n;i++){
		if(st.empty() || st.size() == 1){
			break;
		}
		auto it = st.begin();
		int u = *it;
		++it;
		int v = *it;
		cout<<"? ";
		cout<<u<<" "<<v<<endl;
		cout.flush();
		int res1;
		cin >> res1;
		cout<<"? ";
		cout<<v<<" "<<u<<endl;
		cout.flush();
		int res2;
		cin >> res2;
		if(res1 > res2){
			perm[u-1] = res1;
			st.erase(u);
		}else if(res2 > res1){
			perm[v-1] = res2;
			st.erase(v);
		}
	}
	if(st.size() == 1){
		int sum = 0;
		for(int x:perm){
			sum += x;
		}
		int actual = (n*(n+1))/2;
		int missing = actual - sum;
		int pos = *(st.begin())-1;
		perm[pos] = missing;
	}
	cout<<"! ";
	for(int x:perm){
		cout<<x<<" ";
	}
	cout<<endl;
	cout.flush();
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	while(test--){
		solveQuestion();
	}
	return 0;
}