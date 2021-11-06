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
		int n,k;
		cin>>n>>k;
		vector<int> arr1(n);
		vector<int> arr2(n);
		for(int i=0;i<n;i++){
			cin>>arr1[i];
		}
		for(int i=0;i<n;i++){
			cin>>arr2[i];
		}
		sort(arr1.begin(),arr1.end());
		sort(arr2.begin(),arr2.end(),greater<int>());
		int s = 0,i;
		for(i=0;i<k;i++){
			if(arr2[i]>arr1[i]){
				s+=arr2[i];
			}
			else{
				break;
			}
		}
		for(int idx = i;idx<n;idx++){
			s+=arr1[idx];
		}
		cout<<s<<endl;
	}
	return 0;
}