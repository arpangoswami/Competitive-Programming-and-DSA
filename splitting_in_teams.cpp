#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> arr(n);
	int ct2 = 0,ct1 = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i] == 2){
			ct2++;
		}else{
			ct1++;
		}
	}
	int gps = 0;
	int ones_taken = min(ct2,ct1);
	gps+=ones_taken;
	ct1-=ones_taken;
	gps+=(ct1/3);
	cout<<gps<<endl;
	return 0;
}