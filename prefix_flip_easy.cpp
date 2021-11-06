#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void flipReverse(int i,int j,string &a){
	for(int k=i;k<=j;k++){
		if(a[k] == '1'){
			a[k] = '0';
		}else{
			a[k] = '1';
		}
	}
	int left = i,right = j;
	while(left<right){
		swap(a[left++],a[right--]);
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin >> n;
		string a,b;
		cin >> a >> b;
		vector<int> sol;
		for(int i=n-1;i>=0;i--){
			if(a[i] != b[i]){
				if(a[0] == a[i]){
					flipReverse(0,i,a);
					sol.push_back(i+1);
				}else{
					flipReverse(0,0,a);
					sol.push_back(1);
					flipReverse(0,i,a);
					sol.push_back(i+1);
				}
			}
		}
		cout<<sol.size()<<" ";
		for(int x:sol){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	return 0;
}