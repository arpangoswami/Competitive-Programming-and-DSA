#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> A(n);
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		int evenAtOdd = 0,oddAtEven = 0;
		for(int i=0;i<n;i++){
			if(i%2 == 0 && A[i]%2 == 1){
				oddAtEven++;
			}else if(i%2 == 1 && A[i]%2 == 0){
				evenAtOdd++;
			}
		}
		if(oddAtEven!=evenAtOdd){
			cout<<-1<<endl;
		}else{
			cout<<oddAtEven<<endl;
		}
	}
	return 0;
}