#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int attack,health,n;
	cin >> attack >> health >> n;
	vector<pii> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].first;
	}
	for(int i=0;i<n;i++){
		cin >> arr[i].second;
	}
	int h = health;
	for(int i=0;i<n;i++){
		int div = ((arr[i].second) + (attack-1))/attack;
		h -= (div * arr[i].first);
	}
	if(h >= 0){
		cout<<"YES"<<'\n';
		return;
	}
	for(int i=0;i<n;i++){
		int div = ((arr[i].second) + (attack-1))/attack;
		h += (arr[i].first);
		if(h > 0){
			cout<<"YES"<<'\n';
			return;
		}
		h -= (arr[i].first);
	}
	cout<<"NO"<<'\n';
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