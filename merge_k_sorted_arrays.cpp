#include<bits/stdc++.h>
using namespace std;
int main(void) {
	int k,n;
	cin>>k>>n;
	long **arr = new long*[k];
	int *indices = new int[k];
	for(int i=0;i<k;i++){
		arr[i] = new long[n];
		indices[i] = 0;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	priority_queue<long, vector<long>, greater<long> > minHeap;
	for(int i=0;i<k;i++){
		minHeap.push(arr[i][0]);
	}
	while(!minHeap.empty()){
		int temp = minHeap.top();
		cout<<temp<<" ";
		minHeap.pop();
		for(int j=0;j<k;j++){
			if(arr[j][indices[j]]==temp){
				indices[j]++;
				if(indices[j]<n){
					minHeap.push(arr[j][indices[j]]);
				}
			}
		}
	}
	for(int i=0;i<k;i++){
		delete []arr[i];
	}
	delete []arr;
	delete []indices;
}
