#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    int *arr = new int[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
	    int maxDiff = arr[1] - arr[0];
	    int minElement = arr[0];
	    for(int i=1;i<n;i++){
	        maxDiff = max(maxDiff,arr[i]-minElement);
	        minElement = min(minElement,arr[i]);
	    }
	    if(maxDiff<0) maxDiff = -1;
	    cout<<maxDiff<<endl;
	    delete []arr;
	}
	return 0;
}
