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
	//all of them are 2 pointers
	int maxDiff = 2*(n-m);
	int pointsA = 2*n,pointsB = 2*m;
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
	int i=0,j=0;
	for(;i<n && j<m;){
		//i shots are 2 pointers from A j shots are 2 pointers from B
		int pA = 2*i + 3*(n-i),pB = 2*j + 3*(m-j);
		if((pA - pB) > maxDiff){
			maxDiff = pA - pB;
			pointsA = pA;
			pointsB = pB;
		}else if((pA - pB) == maxDiff && pA > pointsA){
			pointsA = pA;
			pointsB = pB;
		}
		if(arr1[i] > arr2[j]){
			j++;
		}else if(arr1[i] < arr2[j]){
			i++;
		}else{
			i++;
			j++;
		}
	}
	//either i or j or both has/have reached the end
	int pA = 2*i + 3*(n-i),pB = 2*j + 3*(m-j);
	if((pA - pB) > maxDiff){
		maxDiff = pA - pB;
		pointsA = pA;
		pointsB = pB;
	}else if((pA - pB) == maxDiff && pA > pointsA){
		pointsA = pA;
		pointsB = pB;
	}
	cout<<pointsA"\n"
	cout<<pointsB<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}