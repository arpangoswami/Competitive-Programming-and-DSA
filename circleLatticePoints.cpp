#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
double epsilon = 0.001;
double calDist(double xC,double yC,double x,double y){
	return ((xC-x) * (xC-x) + (yC - y) * (yC - y));
}
int highBinSearch(double x,double y,double y_co,double r){
	int low = ceil(x),high = low+r;
	double dist = calDist(x,y,low,y_co);
	if(dist - r*r > epsilon){
		return -1e9;
	}
	int ans = low;
	while(low <= high){
		int mid = (low + high)/2;
		if(calDist(x,y,mid,y_co) - r*r > epsilon){
			high = mid-1;
		}else{
			ans = mid;
			low = mid+1;
		}
	}
	return ans;
}
int lowBinSearch(double x,double y,double y_co,double r){
	int high = floor(x),low = high-r;
	double dist = calDist(x,y,high,y_co);
	if(dist > r*r){
		return -1e9;
	}
	int ans = high;
	while(low <= high){
		int mid = (low + high)/2;
		if(calDist(x,y,mid,y_co) - r*r > epsilon){
			low = mid+1;
		}else{
			ans = mid;
			high = mid-1;
		}
	}
	return ans;
}
void solveQuestion(){
	double x,y,r;
	cin >> x >> y >> r;
	int topY = y+r,botY = y-r;
	x*=1e4;
	y*=1e4;
	if((double)topY > y+r){
		topY--;
	}
	if((double)botY < y-r){
		botY++;
	}
	int ans = 0;
	for(int i=botY;i<=topY;i++){
		int rightX = highBinSearch(x,y,i,r),leftX = lowBinSearch(x,y,i,r);
		if(rightX!=(-1e9) && leftX!=(-1e9)){
			ans+=(rightX - leftX + 1);
		}else if(rightX == (-1e9) && leftX!=(-1e9)){
			ans += (floor(x) - leftX + 1);
		}else if(rightX != (-1e9) && (leftX) == (-1e9)){
			ans += (rightX - ceil(x) + 1);
		}
	}
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}