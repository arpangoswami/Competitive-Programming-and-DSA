#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<string> arr(n);
	for(string &s:arr){
		cin >> s;
	}
	vector<pii> stars;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j] == '*'){
				stars.push_back({i,j});
			}
		}
	}
	if(stars[0].second == stars[1].second){
		if(stars[0].second == 0){
			arr[stars[0].first][1] = '*';
			arr[stars[1].first][1] = '*';
		}else{
			arr[stars[0].first][0] = '*';
			arr[stars[1].first][0] = '*';
		}
	}
	else if(stars[0].first == stars[1].first){
		if(stars[0].first == 0){
			arr[1][stars[0].second] = '*';
			arr[1][stars[1].second] = '*';
		}else{
			arr[0][stars[0].second] = '*';
			arr[0][stars[1].second] = '*';
		}
	}else{
		arr[stars[0].first][stars[1].second] = '*';
		arr[stars[1].first][stars[0].second] = '*';
	}
	for(string x:arr){
		cout<<x<<"\n";
	}
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