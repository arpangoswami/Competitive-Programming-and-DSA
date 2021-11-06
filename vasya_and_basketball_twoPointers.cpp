#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<ll> arr1(n);
	for(int i=0;i<n;++i){
		cin>>arr1[i];
	}
	int m;
	cin>>m;
	vector<ll> arr2(m);
	for(int i=0;i<m;i++){
		cin>>arr2[i];
	}
	arr1.push_back(INT_MAX);
	arr2.push_back(INT_MAX);
	int maxA = 3*n,scoreA = maxA,maxB = 3*m,scoreB = maxB,maxDiff = maxA - maxB;
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
	for(int i=0,j=0;i<n || j<m;){
		if(arr1[i]<arr2[j]){
			scoreA--;
			i++;
		}else if(arr1[i]>arr2[j]){
			scoreB--;
			j++;
		}else{
			scoreB--;
			scoreA--;
			i++;
			j++;
		}
		if((scoreA-scoreB)>maxDiff){
			maxDiff = (scoreA-scoreB);
			maxA = scoreA;
			maxB = scoreB;	
		}
	}
	cout<<maxA<<":"<<maxB<<endl;
	return 0;
}