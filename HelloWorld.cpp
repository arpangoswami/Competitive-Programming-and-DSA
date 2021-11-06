#include <bits/stdc++.h>
using namespace std;
int main(){
	cout<<"Hello World"<<endl;
	int x;
	vector<int> v;
	cin>>x; 
	cout<<x<<endl;
	for(int i=0;i<x;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	for(auto x:v){
		cout<<x<<" ";
	}
	cout<<v[5]<<endl;
	return 0;
}