#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	vector<set<int>> present(m);
	vector<vector<int>> mustPlace(n+1);
	vector<int> freq(n+1);
	vector<int> sol(m);
	for(int i=0;i<m;i++){
		int sz;
		cin >> sz;
		if(sz == 1){
			int v;
			cin >> v;
			mustPlace[v].push_back(i);
			freq[v]++;
		}else{
			for(int j=0;j<sz;j++){
				int v;
				cin >> v;
				freq[v]++;
				present[i].insert(v);
			}
		}
	}
	int maxPlay = (m+1)/2;
	for(int i=1;i<=n;i++){
		if(mustPlace[i].size() > maxPlay){
			cout<<"NO"<<'\n';
			return;
		}
	}
	for(int i=1;i<=n;i++){
		for(int x:mustPlace[i]){
			sol[x] = i;
		}
	}
	int mEle = *max_element(freq.begin(),freq.end());
	if(mEle <= maxPlay){
		for(int i=0;i<m;i++){
			if(sol[i] == 0){
				sol[i] = *(present[i].begin());
			}
		}
	}else{
		int maxEle = -1;
		for(int i=1;i<=n;i++){
			if(freq[i] == mEle){
				maxEle = i;
				break;
			}
		}
		int place = maxPlay;
		place -= mustPlace[maxEle].size();
		for(int i=0;i<m && place > 0;i++){
			if(sol[i] == 0){
				if(present[i].count(maxEle)){
					place--;
					sol[i] = maxEle;
				}
			}
		}
		for(int i=0;i<m;i++){
			if(sol[i] == 0){
				int val = *(present[i].begin());
				if(val == maxEle){
					val = *(present[i].rbegin());
				}
				sol[i] = val;
			}
		}
	}
	cout<<"YES"<<'\n';
	for(int x:sol){
		cout<<x<<" ";
	}
	cout << '\n';
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