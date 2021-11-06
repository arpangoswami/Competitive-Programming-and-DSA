#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
string original = "codeforces";
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll k;
	cin>>k;
	vector<int> cnt(10,1);
	ll product = 1;
	int idx = 0;
	string ans;
	while(product<k){
		product/=cnt[idx];
		cnt[idx]++;
		product*=cnt[idx];
		idx++;
		if(idx == 10){
			idx = 0;
		}
	}
	for(int i=0;i<10;i++){
		int num = cnt[i];
		for(int j=0;j<num;j++){
			ans.push_back(original[i]);
		}
	}
	cout<<ans<<endl;	
	return 0;
}