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
	vector<vector<char>> upsideDown(n,vector<char>(n));
	vector<vector<char>> right(n,vector<char>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> original[i][j];
			left[n-j-1][i] = original[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			upsideDown[n-j-1][i] = left[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			right[n-j-1][i] = upsideDown[i][j];
		}
	}
	vector<vector<char>> originalMelt(n,vector<char>(n,'X'));
	vector<vector<char>> leftMelt(n,vector<char>(n,'X'));
	vector<vector<char>> upsideDownMelt(n,vector<char>(n));
	vector<vector<char>> rightMelt(n,vector<char>(n));
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
	}
	for(int j=0;j<n;j++){
		int cnt = 0;
		for(int i=0;i<n;i++){
			if(left[i][j] == 'C'){
				cnt++;
			}
		}
		for(int i=n-1;i>=(n-cnt);i--){
			leftMelt[i][j] = 'C';
		}
	}
	for(int j=0;j<n;j++){
		int cnt = 0;
		for(int i=0;i<n;i++){
			if(upsideDown[i][j] == 'C'){
				cnt++;
			}
		}
		for(int i=n-1;i>=(n-cnt);i--){
			upsideDownMelt[i][j] = 'C';
		}
	}
	for(int j=0;j<n;j++){
		int cnt = 0;
		for(int i=0;i<n;i++){
			if(right[i][j] == 'C'){
				cnt++;
			}
		}
		for(int i=n-1;i>=(n-cnt);i--){
			rightMelt[i][j] = 'C';
		}
	}
	int ans = 0;
	vector<vector<int>> arr1(n,vector<int>(n,0));
	vector<vector<int>> arr2(n,vector<int>(n,0));
	vector<vector<int>> arr3(n,vector<int>(n,0));
	vector<vector<int>> arr4(n,vector<int>(n,0));
	for(int j=0;j<n;j++){
		if(originalMelt[0][j] == 'X'){
			arr1[0][j] = 1;
		}
		if(leftMelt[0][j] == 'X'){
			arr2[0][j] = 1;
		}
		if(upsideDownMelt[0][j] == 'X'){
			arr3[0][j] = 1;
		}
		if(rightMelt[0][j] == 'X'){
			arr4[0][j] = 1;
		}
	}
	for(int i=1;i<n;i++){
		if(originalMelt[i][0] == 'X'){
			arr1[i][0] = 1;
		}
		if(leftMelt[i][0] == 'X'){
			arr2[i][0] = 1;
		}
		if(upsideDownMelt[i][0] == 'X'){
			arr3[i][0] = 1;
		}
		if(rightMelt[i][0] == 'X'){
			arr4[i][0] = 1;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(originalMelt[i][j] == 'X'){
				arr1[i][j] = 1 + min({arr1[i-1][j],arr1[i][j-1],arr1[i-1][j-1]});
			}else{
				arr1[i][j] = 0;
			}
			if(leftMelt[i][j] == 'X'){
				arr2[i][j] = 1 + min({arr2[i-1][j],arr2[i][j-1],arr2[i-1][j-1]});
			}else{
				arr2[i][j] = 0;
			}
			if(upsideDownMelt[i][j] == 'X'){
				arr3[i][j] = 1 + min({arr3[i-1][j],arr3[i][j-1],arr3[i-1][j-1]});
			}else{
				arr3[i][j] = 0;
			}
			if(rightMelt[i][j] == 'X'){
				arr4[i][j] = 1 + min({arr4[i-1][j],arr4[i][j-1],arr4[i-1][j-1]});
			}else{
				arr4[i][j] = 0;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans = max({ans,arr1[i][j],arr2[i][j],arr3[i][j],arr4[i][j]});
		}
	}
	cout<<ans;
	// cout<<"\n\n";
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<originalMelt[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	// cout<<"\n\n";
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<leftMelt[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	// cout<<"\n\n";
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<arr1[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	// cout<<"\n\n";
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<arr2[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	// cout<<"\n\n";
	return 0;
}