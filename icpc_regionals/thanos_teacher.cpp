#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(2*n);
	for(int &i:arr){
		cin >> i;
	}
	sort(arr.begin(),arr.end());
	n*=2;
	double avg = (arr[0]*1.0 + arr[n-1]*1.0)/2.0;
	int i=1,j=n-2;
	while(i < j){
		if((arr[i]*1.0 + arr[j]*1.0)/2.0 != avg){
			cout<<"IMBALANCED\n";
			return;
		}
		i++;
		j--;
	}
	cout<<"PERFECT\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}