#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
unordered_map<int,int> factors(int x){
	unordered_map<int,int> mp;
	while(x%2 == 0){
		mp[2]++;
		x/=2;
	}
	for(int i=3;i*i<=x;i+=2){
		while(x%i == 0){
			mp[i]++;
			x/=i;
		}
	}
	if(x > 2){
		mp[x]++;
	}
	return mp;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	unordered_map<int,int> mp;
	for(int x:arr){
		unordered_map<int,int> mp2 = factors(x);
		for(auto it:mp2){
			mp[it.first] += it.second;
		}
	}
	unordered_map<int,int> mp2;
	for(int i=0;i<n;i++){
		bool f = true;
		unordered_map<int,int> mp3 = factors(arr[i]);
		for(auto it:mp3){
			mp2[it.first] += it.second;
			mp[it.first] -= it.second;
			if(mp[it.first] == 0){
				mp.erase(it.first);
			}
		}
		int n1 = mp2.size(),n2 = mp.size();
		if(n1 < n2){
			for(auto it:mp2){
				if(mp.count(it.first)){
					f = false;
					break;
				}
			}
		}else{
			for(auto it:mp){
				if(mp2.count(it.first)){
					f = false;
					break;
				}
			}
		}
		if(f){
			cout<<(i+1)<<"\n";
			return;
		}
	}

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