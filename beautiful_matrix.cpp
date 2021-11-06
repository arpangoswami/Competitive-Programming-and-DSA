#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> arr(5,vector<int>(5));
	int x = -1,y = -1;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>arr[i][j];
			if(arr[i][j] == 1){
				x = i;
				y = j;
			}
		}
	}
	cout<< abs(x-2) + abs(y-2)<<endl;
	return 0;
}