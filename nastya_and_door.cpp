#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin>>n>>k;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		int max_peaks = 0;
		int lidx = 1;
		for(int i=0;i<k;i++){
			int left = 0,right = k-1;
			if(i!=left && i!=right && arr[i] > arr[i-1] && arr[i] > arr[i+1]){
				max_peaks++;
			}
		}
		int curr_peaks = max_peaks;
		for(int i=k;i<n;i++){
			int right = i;
			int left = i-k+1;
			if(arr[left] > arr[left-1] && arr[left] > arr[left+1]){
				curr_peaks--;
			}
			if(arr[right-1] > arr[right] && arr[right-1] > arr[right-2]){
				curr_peaks++;
			}
			if(curr_peaks > max_peaks){
				max_peaks = curr_peaks;
				lidx = left+1;
			}
		}
		cout<<max_peaks+1<<" "<<lidx<<"\n";
	}
	return 0;
}