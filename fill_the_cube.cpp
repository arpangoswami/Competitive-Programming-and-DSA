#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<char>> original(n,vector<char>(n));
	vector<vector<char>> left(n,vector<char>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> original[i][j];
			left[n-j-1][i] = original[i][j];
		}
	}
	vector<vector<char>> originalMelt(n,vector<char>(n,'_'));
	vector<vector<char>> leftMelt(n,vector<char>(n,'_'));
	for(int j=0;j<n;j++){
		int cnt = 0;
		for(int i=0;i<n;i++){
			if(original[i][j] == 'C'){
				cnt++;
			}
		}
		for(int i=n-1;i>=(n-cnt);i--){
			originalMelt[i][j] = 'C';
		}
		cnt = 0;
		for(int i=0;i<n;i++){
			if(left[i][j] == 'C'){
				cnt++;
			}
		}
		for(int i=n-1;i>=(n-cnt);i--){
			leftMelt[i][j] = 'C';
		}
	}
	vector<vector<int>> arr1(n,vector<int>(n));
	vector<vector<int>> arr2(n,vector<int>(n));
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==0 || j==0){
				if(originalMelt[i][j] == '_'){
					arr1[i][j] = 1;
				}else{
					arr1[i][j] = 0;
				}
				if(leftMelt[i][j] == '_'){
					arr2[i][j] = 1;
				}else{
					arr2[i][j] = 0;
				}
			}else{
				if(originalMelt[i][j] == '_'){
					arr1[i][j] = 1 + min({arr1[i-1][j-1],arr1[i-1][j],arr1[i][j-1]});
				}else{
					arr1[i][j] = 0;
				}
				if(leftMelt[i][j] == '_'){
					arr2[i][j] = 1 + min({arr2[i-1][j-1],arr2[i-1][j],arr2[i][j-1]});
				}else{
					arr2[i][j] = 0;
				}
			}
			ans = max({ans,arr1[i][j],arr2[i][j]});
		}
	}
	cout<<ans;
	return 0;
}