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
		vector<int> numbers(2*n+1,0);
		for(int i=1;i<=2*n;i++){
			cin>>numbers[i];
		}
		vector<int> odd;
		vector<int> even;
		for(int i=1;i<=2*n;i++){
			if(numbers[i]%2 == 0){
				even.push_back(i);
			}else{
				odd.push_back(i);
			}
		}
		if(odd.size()%2 == 0 && even.size()%2 == 0){
			//int i=2,j=0;
			if(odd.size() >=2 ){
				for(int i=2;i<odd.size();i+=2){
					cout<<odd[i]<<" "<<odd[i+1]<<endl;
				}
				for(int j=0;j<even.size();j+=2){
					cout<<even[j]<<" "<<even[j+1]<<endl;
				}
			}else{
				for(int i=2;i<even.size();i+=2){
					cout<<even[i]<<" "<<even[i+1]<<endl;
				}
			}
			
		}else{
			//int i=1,j = 1;
			for(int i=1;i<odd.size();i+=2){
				cout<<odd[i]<<" "<<odd[i+1]<<endl;
			}
			for(int j=1;j<even.size();j+=2){
				cout<<even[j]<<" "<<even[j+1]<<endl;
			}
		}
	}
	return 0;
}