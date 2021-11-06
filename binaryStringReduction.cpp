#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int kadaneSum(vector<int> &arr,int n){
    int currSum = 0;
    int maxSum = 0;
    for(int x:arr){
        currSum += x;
        maxSum = max(maxSum,currSum);
        currSum = max(currSum,0LL);
    }
    return maxSum;
}
void solveQuestion(){
    int len;
    cin >> len;
	string s;
	cin >> s;
	if(len == 0){
		cout<<0<<'\n';
		return;
	}
	int prevCnt = 1;
    vector<int> temp;
	for(int i=1;i<len;i++){
		if(s[i]!=s[i-1]){
			temp.push_back(prevCnt);
			prevCnt = 1;
		}else{
			prevCnt++;
		}
	}
	temp.push_back(prevCnt);
    int n = temp.size();
    vector<int> temp2(n);
    for(int i=0;i<n;i++){
        temp2[i] = temp[i];
    }
    for(int i=0;i<n;i+=2){
        temp[i] *= -1;
    }
    for(int i=1;i<n;i+=2){
        temp2[i] *= -1;
    }
    int ans = kadaneSum(temp,n);
    ans = max(ans,kadaneSum(temp2,n));
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
