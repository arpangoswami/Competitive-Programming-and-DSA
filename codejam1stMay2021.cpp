#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAX_LIMIT = 100000100001100002;
vector<int> roaring;
bool addNum(int start,int length){
	string s = "";
	for(int i=start;i<(start+length);i++){
		s += to_string(i);
	}
	int num = stoll(s);
	if(num > MAX_LIMIT){
		return false;
	}
	roaring.push_back(num);
	return true;
}
void pre(){
	for(int length=3;length<15;length++){
		bool flag = true;
		for(int start = 1;start<=100000 && flag;start++){
			flag = addNum(start,length);
		}
	}
	sort(roaring.begin(),roaring.end());
}
inline int modNum(int num){
	string s1 = to_string(num);
	s1 += to_string(num+1);
	int ans = stoll(s1);
	return ans;
}
void solveQuestion(){
	int num;
	cin >> num;
	int maxL = 1e18;
	int length = 2LL,low = 1LL,high = 999999998LL;
	if(num >= modNum(high)){
		cout<<MAX_LIMIT<<'\n';
		return;
	}
	int ans = *upper_bound(roaring.begin(),roaring.end(),num);
	int pAns = high;
	while(low <= high){
		int mid = (low + high)/2;
		int modMid = modNum(mid);
		if(modMid > num){
			pAns = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}
	}

	ans = min(ans,modNum(pAns));
	cout << ans << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	cin>>test;
	pre();
	for(int t=1;t<=test;++t){
		cout<<"Case #"<<t<<": ";
		solveQuestion();
	}
	return 0;
}