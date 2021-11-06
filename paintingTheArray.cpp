#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
void solveQuestion() {
	int n;
	cin >> n;
	vi arr(n+1);
	for (int i=1;i<=n;i++) {
		cin >> arr[i];
	}
	vi arr1,arr2;
	arr1.push_back(0);
	arr2.push_back(0);
	vi pos(n+1);
	map<int,vector<int>> indices;
	indices[0].push_back(n+1);
	for(int i=1;i<=n;i++){
		if(arr[i] == arr1.back() && arr[i] != arr2.back()){

		}else if(arr[i] == arr2.back() && arr[i] != arr1.back()){

		}else if(arr[i] =)
	}

}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while (test--) {
		solveQuestion();
	}
	return 0;
}