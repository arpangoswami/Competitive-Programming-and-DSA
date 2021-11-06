#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pr;
int seats(int i,int j,int space){
	if(j<i){
		return 0;
	}
	int ans = 0;
	for(int x=i;x<=j;x+=space){
		ans++;
	}
	return ans;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n,k;
		cin>>n>>k;
		string seating;
		cin>>seating;
		vector<int> ones;
		for(int i=0;i<n;i++){
			if(seating[i] == '1'){
				ones.push_back(i);
			}
		}
		int ct = 0;
		int space = k+1; 
		if(ones.size() == 0){
			ct+=seats(0,n-1,space);
			cout<<ct<<endl;
		}else if(ones.size() == 1){
			ct += seats(0,ones[0]-space,space);
			ct += seats(ones[0]+space,n-1,space);
			cout<<ct<<endl;
		}else{
			ct += seats(0,ones[0]-space,space);
			ct += seats(ones.back()+space,n-1,space);
			for(int i=0;i<ones.size()-1;i++){
				int left = ones[i],right = ones[i+1];
				ct+=seats(left+space,right-space,space);
			}
			cout<<ct<<endl;
		}
	}
	return 0;
}