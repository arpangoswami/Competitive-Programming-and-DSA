#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int>arr(n);
		vector<int> odd;
		vector<int>even;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]%2 == 0){
				even.push_back(arr[i]);
			}
			else{
				odd.push_back(arr[i]);
			}
		}
		bool flag = false;
		if(even.size()%2 == 0 && odd.size()%2 == 0){
			flag = true;
		}
		else{
			for(int i=0;i<odd.size();i++){
				for(int j=0;j<even.size();j++){
					if(abs(even[j] - odd[i]) == 1){
						flag = true;
						break;
					}
				}
				if(flag){
					break;
				}
			}
		}
		if(flag){
			cout<<"YES"<<"\n";
		}
		else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}