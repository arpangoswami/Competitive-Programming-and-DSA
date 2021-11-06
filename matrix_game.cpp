#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int m,n;
		cin>>m>>n;
		int minM = m,minN = n;
		unordered_set<int> rows;
		unordered_set<int> cols;
		vector<vector<int>> arr(m,vector<int>(n));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
				if(arr[i][j] == 1){
					if(rows.count(i) == 0 && cols.count(j) == 0){
						minN--;
						minM--;
						rows.insert(i);
						cols.insert(j);
					}
					else if(rows.count(i) && !cols.count(j)){
						cols.insert(j);
						minN--;
					}
					else if(!rows.count(i) && cols.count(j)){
						rows.insert(i);
						minM--;
					}
				}
			}
		}
		int mini = min(minM,minN);
		//cout<<mini<<endl;
		if(mini%2 == 0){
			cout<<"Vivek"<<"\n";
		}
		else{
			cout<<"Ashish"<<"\n";
		}
	}
	return 0;
}