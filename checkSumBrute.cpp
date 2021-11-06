#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int N;
void change(int &row,int &col,const vector<vector<int>> &arr,int r,int c){
	int cntR = 0,cntC = 0;
	for(int i=0;i<N;i++){
		if(arr[i][c] == -1){
			cntR++;
			row = i;
		}
	}
	for(int j=0;j<N;j++){
		if(arr[r][j] == -1){
			cntC++;
			col = j;
		}
	}
	if(cntR > 1){
		row = -1;
	}
	if(cntC > -1){
		col = -1;
	}
}
vector<pii> sanitise(vector<vector<int>> &arr){
	vector<pii> sol;
	for(int i=0;i<N;i++){
		int c = 0;
		for(int j=0;j<N;j++){
			if(arr[i][j] == -1){
				c++;
			}
		}
		if(c == 1){
			for(int j=0;j<N;j++){
				if(arr[i][j] == -1){
					sol.push_back({i,j});
				}
			}
		}
	}
	for(int j=0;j<N;j++){
		int c = 0;
		for(int i=0;i<N;i++){
			if(arr[i][j] == -1){
				c++;
			}
		}
		if(c == 1){
			for(int i=0;i<N;i++){
				if(arr[i][j] == -1){
					sol.push_back({i,j});
				}
			}
		}
	}
	return sol;
}
void change(vector<vector<int>> &arr,vector<pii> &temp){
	for(pii &x:temp){
		arr[x.first][x.second] = 2;
	}
}
void goBack(vector<vector<int>> &arr,vector<pii> &temp){
	for(pii &x:temp){
		arr[x.first][x.second] = -1;
	}
}
vector<int> poss;
void calCost(vector<vector<int>> &arr,vector<vector<int>> &cost,int r,int c,int &cst){
	if(r == N){
		vector<pii> p1 = sanitise(arr);
		vector<pii> p2 = sanitise(arr);
		change(arr,p1);
		change(arr,p2);
		int ans = cst;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(arr[i][j] == -1){
					ans = 1e8;
				}
			}
		}
		poss.push_back(ans);
		goBack(arr,p2);
		goBack(arr,p1);
	}
	if(c == N){
		calCost(arr,cost,r+1,0,cst);
	}
	if(arr[r][c] == -1){
		int temp = cst;
		calCost(arr,cost,r,c+1,cst);
		int ans = cst;
		cst = temp;
		arr[r][c] = 2;
		vector<pii> p1 = sanitise(arr);
		change(arr,p1);
		vector<pii> p2 = sanitise(arr);
		change(arr,p2);
		cst += cost[r][c];
		calCost(arr,cost,r,c+1,cst);
		ans = min(ans,cst);
		cst = temp;
		goBack(arr,p2);
		goBack(arr,p1);
		arr[r][c] = -1;
	}
}
void solveQ(){
	cin >> N;
	vector<vector<int>> arr(N,vector<int>(N));
	vector<vector<int>> cost(N,vector<int>(N));
	vector<int> row(N);
	vector<int> col(N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> arr[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> cost[i][j];
		}
	}
	for(int i=0;i<N;i++){
		cin >> row[i];
	}
	for(int i=0;i<N;i++){
		cin >> col[i];
	}
	vector<pii> t = sanitise(arr);
	change(arr,t);
	int cst = 0;
	calCost(arr,cost,0,0,cst);
	cout<<cst<<'\n';
	for(int x:poss){
		cout<<x<<" ";
	}
	cout<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveQ();
	}
	return 0;
}