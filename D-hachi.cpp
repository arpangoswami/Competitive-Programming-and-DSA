#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	string s;
	cin >> s;
	int n = s.size();
	if(n == 1){
		int val = stoi(s);
		if(val % 8 == 0){
			cout<<"Yes";
		}else{
			cout<<"No";
		}
		return;
	}else if(n == 2){
		int v1 = stoi(s);
		reverse(s.begin(),s.end());
		int v2 = stoi(s);
		if(v1 % 8 == 0 || v2 % 8 == 0){
			cout<<"Yes";
		}else{
			cout<<"No";
		}
		return;
	}
	unordered_map<int,int> start;
	start[2] = 11;
	start[4] = 14;
	start[6] = 13;
	start[8] = 12;
	int mp[10] = {0};
	for(char c:s){
		mp[c - '0']++;
	}

	if(mp[2] == 0 && mp[4] == 0 && mp[6] == 0 && mp[8] == 0){
		cout<<"No";
		return;
	}
	for(int i=2;i<=8;i+=2){
		if(mp[i] <= 0){
			continue;
		}
		mp[i]--;
		for(int j=start[i];j<=99;j+=4){
			int temp = j;
			int val1 = temp%10;
			bool f1 = false,f2 = false;
			if(mp[val1] > 0){
				f1 = true;
				mp[val1]--;
			}
			temp/=10;
			int val2 = temp%10;
			if(mp[val2] > 0){
				f2 = true;
				mp[val2]--;
			}
			if(f1 && f2){
				cout<<"Yes";
				return;
			}
			if(f1)
				mp[val1]++;
			if(f2)
				mp[val2]++;
		
		}
		
		mp[i]++;
	}
 
	cout<<"No";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}