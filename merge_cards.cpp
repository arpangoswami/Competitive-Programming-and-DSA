#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
void recSolve(vector<int> arr,int &ct,int &score){
	if((int)arr.size() == 2){
		ct++;
		score += (arr[0] + arr[1]);
		return;
	}
	int n = arr.size();
	for(int i=0;i<(n-1);i++){
		vector<int> temp;
		int first = i,second = i+1;
		for(int j=0;j<first;j++){
			temp.push_back(arr[j]);
		}
		int sum = arr[first] + arr[second];
		temp.push_back(sum);
		score += sum;
		for(int j=second+1;j<n;j++){
			temp.push_back(arr[j]);
		}
		recSolve(temp,ct,score);
	}
}
void solveQ(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int ct = 0;
	int score = 0;
	recSolve(arr,ct,score);
	double prob = (double)score/(double)ct;
	cout<<fixed<<setprecision(6)<<prob<<"\n";
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