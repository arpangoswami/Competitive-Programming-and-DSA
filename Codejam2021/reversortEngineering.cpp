#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
void printArr(vector<int> &arr){
	for(int x:arr){
		cout << x << " ";
	}
	cout << '\n';
}
void reverse(vector<int> &arr,int i,int j){
	while(i < j){
		swap(arr[i++],arr[j--]);
	}
}
int calReverse(vector<int> arr){
	int n = arr.size();
	auto minIdx = [&](int start,int finish){
		int minm = arr[start],ans = start;
		for(int i=start+1;i<=finish;i++){
			if(arr[i] < minm){
				minm = arr[i];
				ans = i;
			}
		}
		return ans;
	};
	int ans = 0;
	for(int i=1;i<=(n-1);i++){
		int setIdx = i-1;
		int idx = minIdx(setIdx,n-1);
		ans += (idx - setIdx + 1);
		reverse(arr,setIdx,idx);
	}
	return ans;
}
void solveQ(){
	int n,c;
	cin >> n >> c;
	if(c < (n-1) || c >= n*(n+1)/2 ){
		cout << "IMPOSSIBLE" <<'\n';
		return;
	}	
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		arr[i] = i+1;
	}

	if(c == n-1){
		sort(arr.begin(),arr.end());
		printArr(arr);
	}

	else{
		if(n <= 3){
			while(true){
				if(calReverse(arr) == c){
					printArr(arr);
					return;
				}
				next_permutation(arr.begin(),arr.end());
			}
		}else{
			int add = (n-1);
			int revVal = (n-1);
			int minIdx = 0,maxIdx = n-1;
			int idx = minIdx;
			//cout << n << "  "<<c << "revVal: "<<revVal<<'\n';
			//cout<<"lmao"<<'\n';
			while(revVal < c){
				if(revVal + add <= c){
					swap(arr[idx],arr[maxIdx]);
					sort(arr.begin()+minIdx,arr.begin()+maxIdx+1,greater<int>());
					idx = maxIdx-1;
					maxIdx--;
				}else{
					int diff = c - revVal;
					int idx = minIdx + diff;
					swap(arr[idx],arr[minIdx]);
					sort(arr.begin()+minIdx,arr.begin()+idx,greater<int>());
					sort(arr.begin()+idx+1,arr.begin()+maxIdx+1);
					printArr(arr);
					return; 
				}
				revVal += add;
				add--;
				if(revVal == c){
					printArr(arr);
					return;
				}
				if(revVal + add <= c){
					swap(arr[idx],arr[minIdx]);
					sort(arr.begin()+minIdx+1,arr.begin()+maxIdx);
					idx = minIdx+1;
					minIdx++;
				}else{
					int diff = c - revVal;
					int idx = maxIdx - diff;
					swap(arr[idx],arr[maxIdx]);
					sort(arr.begin()+minIdx,arr.begin()+idx,greater<int>());
					sort(arr.begin()+idx+1,arr.begin()+maxIdx+1);
					printArr(arr);
					return;
				}
				revVal += add;
				add--;
				if(revVal == c){
					printArr(arr);
					return;
				}
			}
		}
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveQ();
	}
	return 0;
}