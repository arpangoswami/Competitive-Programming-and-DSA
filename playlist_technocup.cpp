#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	if(n == 1){
		if(arr[0] == 1){
			cout<<"1 1"<<'\n';
		}else{
			cout<<"0"<<'\n';
		}
		return;
	}
	vector<int> nextSong(n);
	vector<int> erased(n);
	queue<pii> badSongs;
	for(int i=0;i<n;i++){
		nextSong[i] = (i+1)%n;
		if(__gcd(arr[i],arr[nextSong[i]]) == 1){
			badSongs.push({i,nextSong[i]});
		}
	}
	vi del;
	while(!badSongs.empty()){
		pii temp = badSongs.front();
		badSongs.pop();
		if(erased[temp.first] == 1){
			continue;
		}
		del.push_back(temp.second);
		erased[temp.second] = 1;
		nextSong[temp.first] = nextSong[temp.second];
		if(__gcd(arr[temp.first],arr[nextSong[temp.first]]) == 1){
			badSongs.push({temp.first,nextSong[temp.first]});
		}
	}
	cout<<del.size()<<" ";
	for(int x:del){
		cout<<(x+1)<<" ";
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