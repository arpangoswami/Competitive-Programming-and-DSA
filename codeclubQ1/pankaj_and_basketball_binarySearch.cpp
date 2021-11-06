#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr1(n);
	for(int &i:arr1){
		cin >> i;
	}
	int m;
	cin >> m;
	vector<int> arr2(m);
	for(int &i:arr2){
		cin >> i;
	}
	//all shots 2 pointers
	int maxDiff = 2*(n-m);
	int pointsA = 2*n,pointsB = 2*m;
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
	for(int i=0;i<n;i++){
		//all shots upto distance (arr[i] - 1) is worth 2 points and each shot is worth 3 points for d >= arr[i]
		int idx = lower_bound(arr2.begin(),arr2.end(),arr1[i]) - arr2.begin();
		int pA = 2*i + 3*(n-i);
		int pB = 2*idx + 3*(m-idx);
		if((pA - pB) > maxDiff){
			maxDiff = pA - pB;
			pointsA = pA;
			pointsB = pB;
		}else if((pA - pB) == maxDiff && pA > pointsA){
			pointsA = pA;
			pointsB = pB;
		}
	}
	cout<<pointsA<<"\n"<<pointsB<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	#ifndef ONLINE_JUDGE
		freopen("tc11.txt", "r", stdin);
		freopen("output11.txt", "w", stdout);
	#endif
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}