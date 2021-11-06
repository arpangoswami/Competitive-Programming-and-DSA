#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
bool check(int n,int i){
	int steps = 0;
	while(steps <= 7){
		if(n > i){
			n = (n + i-1)/i;
			steps++;
		}else{
			i = (i + n-1)/n;
			steps++;
		}
		if(i == 2 && n == 1){
			break;
		}
		if(n == 2 && i == 1){
			break;
		}
	}
	return (n == 1 && i == 2) || (i == 1 && n == 2);
}
vector<pii> steps(int n,int i){
	vector<pii> sol;
	int steps = 0;
	int tempI = i,tempN = n;
	while(steps <= 7){
		if(tempN > tempI){
			tempN = (tempN + tempI - 1)/tempI;
			sol.push_back({n,i});
			steps++;
		}else{
			tempI = (tempI + tempN-1)/tempN;
			sol.push_back({i,n});
			steps++;
		}
		if(tempI == 2 && tempN == 1){
			break;
		}
		if(tempN == 2 && tempI == 1){
			break;
		}
	}
	return sol;
}
void solveQuestion(){
	int n;
	cin >> n;
	if(n == 2){
		cout<<0<<'\n';
		return;
	}
	int ans = 1;
	vector<pii> arr;
	for(int i=2;i<=(n-1);i++){
		if(check(n,i)){
			arr = steps(i,n);
			ans = i;
			break;
		}
	}
	cout<<(n-3) + arr.size()<<'\n';
	for(int i=2;i<=(n-1);i++){
		if(i == ans){
			continue;
		}
		cout<<i<<" "<<n<<'\n';
	}
	for(pii x:arr){
		cout<<x.first<<" "<<x.second<<'\n';
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