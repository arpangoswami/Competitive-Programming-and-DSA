#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end(),greater<int>());
	vector<int> perm;
	perm.push_back(arr[0]);
	int gcd = perm.back();
	unordered_set<int> picked;
	picked.insert(0);
	for(int i=1;i<n;i++){
		if(gcd == 1){
			break;
		}
		int minG = 0,idx = -1;
		for(int j=0;j<n;j++){
			if(picked.count(j)){
				continue;
			}
			int tempG = __gcd(gcd,arr[j]);
			if(tempG > minG){
				idx = j;
				minG = tempG;
			}
		}
		picked.insert(idx);
		perm.push_back(arr[idx]);
		gcd = __gcd(gcd,perm.back());
	}
	if(gcd == 1){
		for(int i=0;i<n;i++){
			if(picked.count(i) == 0){
				perm.push_back(arr[i]);
			}
		}
	}
	for(int x:perm){
		cout<<x<<" ";
	}
	cout<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}