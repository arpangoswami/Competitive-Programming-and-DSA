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
		string a,b;
		cin>>a>>b;
		vector<int> freq(26,0);
		int n = a.size();
		for(int i=0;i<n;i++){
			freq[a[i] - 'A']++;
		}
		bool f = false;
		for(int i=0;i<n && !f;i++){
			char c = a[i];
			int idx = c - 'A';
			for(int j=0;j<idx && !f;j++){
				if(freq[j] > 0){
					for(int k=n-1;k>=i+1 && !f;k--){
						if(a[k] == (char)(j+'A')){
							swap(a[k],a[i]);
							f = true;
							break;
						}
					}
					break;
				}
			}
			freq[idx]--;
		}
		if(a < b){
			cout<<a<<"\n";
		}else{
			cout<<"---"<<"\n";
		}
	}
	return 0;
}