#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int salarySup[501][501];
int salaries[2501];
int parents[2501];
void solveQuestion(){
	int k;
	cin >> k;
	memset(salarySup,0,sizeof(salarySup));
	memset(salaries,0,sizeof(salaries));
	memset(parents,-1,sizeof(parents));
	int maxm = 0;
	set<int> numberOfNodes;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			cin >> salarySup[i][j];
			numberOfNodes.insert(salarySup);
			if(i == j){
				salaries[i] = salarySup[i][i];
			}
			maxm = max(maxm,salarySup[i][j]);
		}
	}
	int n = numberOfNodes.size();
	int root = n;
	salaries[n] = maxm;
	
	for(int i=1;i<=n;i++){
		cout<<salaries[i]<<" ";
	}
	cout<<'\n';
	for(int i=1;i<=n;i++){
		if(parents[i] == -1){
			cout<<i<<'\n';
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(parents[i] != -1){
			cout<<i<<" "<<parents[i]<<'\n';
		}
	}

}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}