#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
bool allPossible(vector<int> &arr,int n,int a,int b,int c){
	if(n == 0){
		int sz = arr.size();
		int maxLeft = 0,maxRight = 0;
		int cntA = 0,cntB = 0;
		int maxm = 0;
		for(int i=0;i<sz;i++){
			if(arr[i] >= maxLeft){
				cntA++;
				maxLeft = arr[i];
			}
			maxm = max(maxm,arr[i]);
		}
		for(int i=sz-1;i>=0;i--){
			if(arr[i] >=maxRight){
				cntB++;
				maxRight = arr[i];
			}
		}
		if(cntA!=a || cntB!=b){
			return false;
		}
		int cntC = 0;
		for(int x:arr){
			if(x == maxm){
				cntC++;
			}
		}
		if(cntC!=c){
			return false;
		}
		return true;
	}
	for(int i=1;i<=arr.size();i++){
		arr[n-1] = i;
		bool f = allPossible(arr,n-1,a,b,c);
		if(f){
			return true;
		}
	}
	arr[n-1] = 0;
	return false;

}
void solve2(int n,int a,int b,int c){
	bool f = false;
	vector<int> arr(n);
	f = allPossible(arr,n,a,b,c);
	if(!f){
		cout<<"IMPOSSIBLE"<<"\n";
		return;
	}else{
		for(int x:arr){
			cout<<x<<" ";
		}
		cout<<"\n";
		return;
	}
}
void solveQuestion(){
	int n,a,b,c;
	cin >> n >> a >> b >> c;
	if(n <= 5){
		solve2(n,a,b,c);
		return;
	}
	if(c == 0){
		cout<<"IMPOSSIBLE"<<"\n";
		return;
	}
	int onlyF = a-c;
	int onlyS = b-c;
	vector<int> arr(n+1);
	if(c > min(a,b)){
		cout<<"IMPOSSIBLE"<<"\n";
		return;
	}
	if((onlyF + onlyS + c) > n){
		cout<<"IMPOSSIBLE"<<"\n";
		return;
	}
	if(onlyF == 0 && onlyS == 0){
		if(c < 2){
			cout<<"IMPOSSIBLE"<<"\n";
			return;
		}else{
			int invisible = n - c;
			for(int i=1;i<=n;i++){
				arr[i] = 1;
			}
			for(int i=1;i<=c-1;i++){
				arr[i] = 3;
			}
			arr[n] = 3;
			for(int i=1;i<=n;i++){
				cout<<arr[i]<<" ";
			}
			cout<<"\n";
			return;
		}
	}
	if(c == n){
		for(int i=1;i<=n;i++){
			cout<<1<<" ";
		}
		cout<<"\n";
		return;
	}
	if((onlyF + onlyS + c) <= n && onlyF!=0){
		int invisible = n - (onlyF + onlyS + c);
		for(int i=1;i<=onlyF;i++){
			arr[i] = 2;
		}
		for(int i=onlyF+1;i<=onlyF+invisible;i++){
			arr[i] = 1;
		}
		for(int i=onlyF+invisible+1;i<=onlyF+invisible+c;i++){
			arr[i] = 3;
		}
		for(int i=onlyF+invisible+c+1;i<=n;i++){
			arr[i] = 2;
		}
		for(int i=1;i<=n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	if((onlyF + onlyS + c) <= n && onlyF==0){
		int invisible = n - (onlyF + onlyS + c);
		for(int i=1;i<=c;i++){
			arr[i] = 3;
		}
		for(int i=c+1;i<=c+invisible;i++){
			arr[i] = 1;
		}
		for(int i=c+invisible+1;i<=n;i++){
			arr[i] = 2;
		}
		for(int i=1;i<=n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return;
	}else{
		cout<<"IMPOSSIBLE"<<"\n";
		return;
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
		solveQuestion();
	}
	return 0;
}