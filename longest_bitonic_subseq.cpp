#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int longestSubseqLength(const vector<int> &A){
	int n = A.size();
    if(n == 0){
        return 0;
    }
    vector<int> inc(n,1);
    vector<int> dec(n,1);
    for(int i=1;i<n;i++){
    	for(int j=0;j<i;j++){
    		if(A[j]<A[i]){
    			inc[i] = max(inc[i],1+inc[j]);
    		}
    	}
    }
    for(int i=n-2;i>=0;i--){
    	for(int j=n-1;j>i;j--){
    		if(A[j]<A[i]){
    			dec[i] = max(dec[i],1+dec[j]);
    		}
    	}
    }
    int maxm = 1;
    for(int i=0;i<n;i++){
    	maxm = max(maxm,inc[i]+dec[i]-1);
    }
    return maxm;
}
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
		cout<<longestSubseqLength(A)<<endl;
	}
	return 0;
}