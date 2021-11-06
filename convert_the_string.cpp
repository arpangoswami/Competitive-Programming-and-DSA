#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll power(ll a,ll b){
	if(b == 0){
		return 1;
	}
	ll smallAns = power(a,b/2);
	if(b&1){
		return smallAns*smallAns*a;
	}
	return smallAns*smallAns;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		bool flag = true;
		for(int i=0;i<n;i++){
			if(a[i]<b[i]){
				flag = false;
				break;
			}
		}
		set<char,greater<int>> s1,s2;
		for(int i=0;i<n;i++){
			s1.insert(a[i]);
			s2.insert(b[i]);
		}
		for(char c:s2){
			if(s1.count(c) == 0){
				flag = false;
				break;
			}
		}
		if(!flag){
			cout<<-1<<endl;
		}else{
			set<char,greater<char>> different;
			for(int i=0;i<n;i++){
				if(a[i]>b[i]){
					different.insert(b[i]);
				}
			}
			cout<<different.size()<<endl;
			auto it=different.begin();
			while(it!=different.end()){
				unordered_set<int> solution;
				for(int i=0;i<n;i++){
					if(b[i] == *it){
						solution.insert(i);
					}
				}
				for(int i=0;i<n;i++){
					if(a[i] == *it){
						solution.insert(i);
						break;
					}
				}
				cout<<solution.size()<<" ";
				for(int x:solution){
					cout<<x<<" ";
				}
				cout<<endl;
				++it;
			}
		}
	}
	return 0;
}