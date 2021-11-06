#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
bool cmp(string &s1,string &s2){
	int m = s1.size(),n = s2.size();
	int length = min(m,n);
	bool flag = false;
	for(int i=0;i<length;i++){
		if(s1[i] < s2[i]){
			return true;
		}else if(s1[i] > s2[i]){
			return false;
		}
	}
	return m > n;
}
int main() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end(),cmp);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\n";
	}
	return 0;
}