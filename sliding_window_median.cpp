#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int findMedian(multiset<int,greater<int>> &m1,multiset<int> &m2){
	if(m1.size() == m2.size() || m1.size() == m2.size() + 1){
		return (*m1.begin());
	}
	return (*m2.begin());
}
void balance(multiset<int,greater<int>> &m1,multiset<int> &m2){
	if(m1.size() == m2.size() || m1.size() == m2.size() + 1 || m1.size() + 1 == m2.size()){
		return;
	}
	else if(m1.size() >= m2.size() + 2){
		multiset<int,greater<int>>::iterator it = m1.begin();
		int num = *it;
		m1.erase(it);
		m2.insert(num);
	}else{
		multiset<int>::iterator it = m2.begin();
		int num = *it;
		m2.erase(it);
		m1.insert(num);
	}
}
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	multiset<int,greater<int>> m1;
	multiset<int> m2;
	for(int i=0;i<k;i++){
		m1.insert(arr[i]);
	}
	for(int i=0;i<(k/2);i++){
		multiset<int>::iterator it = m1.begin();
		int num = *it;
		m1.erase(it);
		m2.insert(num);
	}
	for(int i=k;i<n;i++){
		int med = findMedian(m1,m2);
		cout<<med<<" ";
		int toErase = arr[i-k];
		int toInsert = arr[i];
		bool found = false;
		multiset<int,greater<int>>::iterator it = m1.find(toErase);
		if(it!=m1.end()){
			m1.erase(it);
			found = true;
		}
		if(!found){
			m2.erase(m2.find(toErase));
		}
		if(toInsert >= med){
			m2.insert(toInsert);
		}else{
			m1.insert(toInsert);
		}
		balance(m1,m2);
	}
	int med = findMedian(m1,m2);
	cout<<med;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}