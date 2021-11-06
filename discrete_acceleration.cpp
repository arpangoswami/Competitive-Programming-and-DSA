#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,l;
	cin >> n >> l;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int i=0,j = n-1;
	double ans = 0;
	int u = 1,v = 1;
	double posX = 0.00,posY = l;
	while(i <= j){
		double timeX = ((double)arr[i] - posX)/(double)u;
		double timeY = (posY - (double)arr[j])/(double)v;
		if(timeX < timeY){
			ans += timeX;
			posX += (double)u * timeX;
			posY -= (double)v * timeX;
			i++;
			u++;
		}else if(timeX > timeY){
			ans += timeY;
			posX += (double)u * timeY;
			posY -= (double)v * timeY;
			j--;
			v++;
		}else{
			ans += timeX;
			posX += (double)u * timeX;
			posY -= (double)v * timeX;
			i++;
			j--;
			u++;
			v++;
		}
	}
	ans += (double)(posY - posX)/(double)(u + v);
	cout<<fixed<<setprecision(12)<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}