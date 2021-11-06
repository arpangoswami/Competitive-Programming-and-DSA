#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> &p1,pair<int,int> &p2){
	if(p1.first == p2.first){
		return p1.second < p2.second;
	}
	return p1.first > p2.first;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int pat;
		cin >> pat;
		vector<pair<int,int>> dis(pat);
		for(int i=0;i<pat;i++){
			cin >> dis[i].first;
			dis[i].second = i;
		}
		sort(dis.begin(),dis.end(),cmp);
		vector<int> sol(pat);
		for(int i=0;i<pat;i++){
			int index = dis[i].second;
			sol[index] = (i+1);
		}
		for(int i=0;i<pat;i++){
			cout<<sol[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}