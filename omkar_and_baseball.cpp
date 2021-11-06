#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vi arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		bool alreadySorted = true;
		for(int i=0;i<n;i++){
			if(arr[i]!=(i+1)){
				alreadySorted = false;
				break;
			}
		}
		if(alreadySorted){
			cout<<0<<"\n";
		}else{
			bool correctPlace = false;
			int idx = -1;
			for(int i=0;i<n;i++){
				if(arr[i] == (i+1)){
					correctPlace = true;
					idx = i;
					break;
				}
			}
			if(correctPlace){
				bool flag = true;
				int id1 = -1,id2 = -1;
				for(int i=0;i<n;i++){
					if(arr[i]!=(i+1)){
						id1 = i;
						break;
					}
				}
				for(int i=n-1;i>=0;i--){
					if(arr[i]!=(i+1)){
						id2 = i;
						break;
					}
				}
				for(int i=id1;i<=id2;i++){
					if(arr[i] == (i+1)){
						flag = false;
						break;
					}
				}
				if(flag){
					cout<<1<<"\n";
				}else{
					cout<<2<<"\n";
				}
			}else{
				cout<<1<<"\n";
			}
		}
	}
	return 0;
}