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
	for(int i=0;i<m;++i){
		cin>>arr2[i];
	} 
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
	ll maxDiff = LONG_MIN;
	ll maxA = LONG_MIN,maxB = LONG_MIN;
	for(int i=0;i<n;i++){
		ll dist = arr1[i];
		auto it = lower_bound(arr2.begin(),arr2.end(),dist);
		if(it == arr2.end()){
			ll pA = 2*i + 3*(n-i);
			ll pB = 2*m;
			if((pA - pB)>=maxDiff){
				if(pA-pB == maxDiff){
					if(pA>maxA){
						maxA = pA;
						maxB = pB;
					}
				}else{
					maxA = pA;
					maxB = pB;
					maxDiff = maxA - maxB;
				}
			}
		}
		else{
			ll idx = it - arr2.begin();
			ll pA = 2*i + 3*(n-i);
			ll pB = 2*idx + 3*(m-idx);
			if((pA - pB)>=maxDiff){
				if(pA-pB == maxDiff){
					if(pA>maxA){
						maxA = pA;
						maxB = pB;
					}
				}else{
					maxA = pA;
					maxB = pB;
					maxDiff = maxA - maxB;
				}
			}
		}
	}
	cout<<maxA<<":"<<maxB<<endl;	
	return 0;
}