#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sumOfDigits(int n){
	int ans = 0;
	while(n > 0){
		ans+=n%10;
		n/=10;
	}
	return ans;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int chef = 0,morty = 0;
		for(int i=0;i<n;i++){
			int pt1,pt2;
			cin>>pt1>>pt2;
			int sd1 = sumOfDigits(pt1),sd2 = sumOfDigits(pt2);
			if(sd1 > sd2){
				chef++;
			}else if(sd1 < sd2){
				morty++;
			}else{
				chef++;
				morty++;
			}
		}
		if(chef > morty){
			cout<<0<<" "<<chef<<"\n";
		}else if(chef < morty){
			cout<<1<<" "<<morty<<"\n";
		}else{
			cout<<2<<" "<<chef<<"\n";
		}
	}
	return 0;
}