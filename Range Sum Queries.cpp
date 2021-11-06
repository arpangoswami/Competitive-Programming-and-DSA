#include <bits/stdc++.h>
using namespace std;
void update(int *BIT,int idx,int val,int n){
    while(idx<=n){
        BIT[idx]+=val;
        idx+=idx&(-idx);
    }
}
int query(int *BIT,int idx){
    int s = 0;
    while(idx>0){
        s+=BIT[idx];
        idx-=idx&(-idx);
    }
    return s;
}
int main() {
	//code
	int test;
	cin>>test;
	//cout<<test<<endl;
	while(test--){
	    int n,q;
	    cin>>n>>q;
	    int *BIT = new int[n+1]();
	    int *arr = new int[n+1]();
	    for(int i=1;i<=n;i++){
	        cin>>arr[i];
	        update(BIT,i,arr[i],n);
	    }
	    while(q--){
	        char type;
	        cin>>type;
	        if(type == 'G'){
                    //cout<<"yoo"<<endl;
	            int left,right;
	            cin>>left>>right;
	            if(left == 0){
                    cout<<query(BIT,right+1)<<endl;
	            }
	            else{
                    cout<<query(BIT,right+1) - query(BIT,left)<<endl;
                }
	        }
	        else{
	            int idx,value;
	            cin>>idx>>value;
	            int temp = arr[idx+1];
	            arr[idx+1] = value;
	            update(BIT,idx+1,-temp,n);
	            update(BIT,idx+1,value,n);
	        }
	    }
	    delete []BIT;
	    delete []arr;
	}
	return 0;
}
