#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
bool checkPrime(int n){
	int i=2;
	if(n%2 == 0){
		return false;
	}
	for(int i=3;i*i<=n;i+=2){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		unordered_set<int> power2;
		for(int i=2;i<=30;i++){
			power2.insert(1<<i);
		}
		if(n%2 == 1){
			if(n == 1){
				cout<<"FastestFinger"<<"\n";
			}else{
				cout<<"Ashishgup"<<endl;
			}
		}else{
			if(power2.count(n)){
				cout<<"FastestFinger"<<endl;
			}
			else if(n == 2){
				cout<<"Ashishgup"<<endl;
			}else{
				int temp = n;
				temp/=2;
				if(temp%2 == 1){
					if(checkPrime(temp))
						cout<<"FastestFinger"<<endl;
					else
						cout<<"Ashishgup"<<endl;
				}else{
					cout<<"Ashishgup"<<endl;
				}
			}
		}
	}
	return 0;
}