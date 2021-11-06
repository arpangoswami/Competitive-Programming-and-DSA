#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
struct person{
	int height;
	int width;
	int index;
	person(){
		height = 0;
		width = 0;
		index = 0;
	}
	person(int ht,int wd,int i){
		height = ht;
		width = wd;
		index = i;
	}
};
bool compare(person &p1,person &p2){
	if(p1.height == p2.height){
		return p1.width < p2.width;
	}
	return p1.height < p2.height;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<person> arr(n);
	vector<person> sol(2*n);
	int idx = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i].height >> arr[i].width;
		arr[i].index = i+1;
		sol[idx++] = arr[i];
		sol[idx++] = person(arr[i].width,arr[i].height,i+1);
	}
	sort(sol.begin(),sol.end(),compare);
	int prev = sol[0].height,start = 0;
	map<int,int> mp;
	for(int i=0;i<2*n;i++){
		if(sol[i].height != sol[i-1].height){
			mp[prev] = start;
			start = i;
			prev = sol[i].height;
		}
	}
	mp[prev] = start;
	vector<pii> mini(2*n);
	int minWidth = sol[0].width,minIdx = sol[0].index;
	mini[0] = {minWidth,minIdx};
	for(int i=1;i<2*n;i++){
		if(sol[i].width < minWidth){
			minWidth = sol[i].width;
			minIdx = sol[i].index;
		}
		mini[i] = {minWidth,minIdx};
	}
	vector<bool> visited(n+1,false);
	vector<int> ans(n+1,-1);
	for(int i=0;i<2*n;i++){
		if(!visited[sol[i].index]){
			int index = mp[sol[i].height];
			int minm = 2e9;
			if(index > 0){
				minm = mini[index-1].first;
				if(minm < sol[i].width){
					ans[sol[i].index] = mini[index-1].second;
					visited[sol[i].index] = true;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<'\n';
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