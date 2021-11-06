#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> painters(m);
	for(int &i:a){
		cin >> i;
	}
	for(int &i:b){
		cin >> i;
	}
	for(int &i:painters){
		cin >> i;
	}
	map<int,vector<int>> change,same;
	for(int i=0;i<n;i++){
		if(a[i] != b[i]){
			change[b[i]].push_back(i);		
		}else{
			same[b[i]].push_back(i);
		}
	}
	vector<int> colors(m);
	int laterPaint = -1;
	for(int i=m-1;i>=0;i--){
		int col = painters[i];
		if(change[col].size()){
			int idx = change[col].back();
			change[col].pop_back();
			same[col].push_back(idx);
			colors[i] = idx;
			laterPaint = idx;
		}else if(same[col].size()){
			int idx = same[col].back();
			colors[i] = idx;
			laterPaint = idx;
		}else if(laterPaint != -1){
			colors[i] = laterPaint;
		}else{
			cout<<"NO"<<'\n';
			return;
		}
	}
	for(int i=0;i<m;i++){
		a[colors[i]] = painters[i];
	}
	for(int i=0;i<n;i++){
		if(a[i] != b[i]){
			cout<<"NO"<<'\n';
			return;
		}
	}
	cout<<"YES"<<'\n';
	for(int x:colors){
		cout<<(x+1)<<" ";
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