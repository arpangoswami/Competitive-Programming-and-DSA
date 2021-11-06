#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct node{
	ll sum;
	ll sweetness;
};
void buildTree(vector<ll> &arr,vector<node> &tree,int start,int end,int treeNode){
	if(start == end){
		node n;
		n.sum = arr[start];
		n.sweetness = arr[start];
		tree[treeNode] = n;
		return;
	}
	int mid = start + (end - start)/2;
	buildTree(arr,tree,start,mid,2*treeNode+1);
	buildTree(arr,tree,mid+1,end,2*treeNode+2);
	node n;
	node n1 = tree[2*treeNode+1];
	node n2 = tree[2*treeNode+2];
	n.sum = n1.sum-n2.sum;
	int size = (mid-start+1);
	if(size%2 == 0){
		n.sweetness = n1.sweetness + n2.sweetness + (size+1)*n2.sum;
	}else{
		n.sweetness = n1.sweetness - n2.sweetness - (size+1)*n2.sum;
	}
	tree[treeNode] = n;
}
void updateTree(vector<ll> &arr,vector<node> &tree,int start,int end,int treeNode,int idx,ll value){
	if(start == end){
		arr[idx] = value;
		node nt;
		nt.sum = value;
		nt.sweetness = value;
		tree[treeNode] = nt;
		return;
	}
	int mid = start + (end - start)/2;
	if(idx>mid){
		updateTree(arr,tree,mid+1,end,2*treeNode+2,idx,value);
	}else{
		updateTree(arr,tree,start,mid,2*treeNode+1,idx,value);
	}
	node n;
	node n1 = tree[2*treeNode+1];
	node n2 = tree[2*treeNode+2];
	n.sum = n1.sum-n2.sum;
	int size = (mid-start+1);
	if(size%2 == 0){
		n.sweetness = n1.sweetness + n2.sweetness + (size+1)*n2.sum;
	}else{
		n.sweetness = n1.sweetness - n2.sweetness - (size+1)*n2.sum;
	}
	tree[treeNode] = n;
}
node query(vector<node> &tree,int start,int end,int treeNode,int left,int right){
	if(start>right || end<left){
		node n;
		n.sweetness = 0;
		n.sum = 0;
		return n;
	}
	if(start>=left && end<=right){
		return tree[treeNode];
	}
	int mid = start + (end - start)/2;
	node n1 = query(tree,start,mid,2*treeNode+1,left,right);
	node n2 = query(tree,mid+1,end,2*treeNode+2,left,right);
	node n;
	n.sum = n1.sum-n2.sum;
	int size = (mid-start+1);
	if(size%2 == 0){
		n.sweetness = n1.sweetness + n2.sweetness + (size+1)*n2.sum;
	}else{
		n.sweetness = n1.sweetness - n2.sweetness - (size+1)*n2.sum;
	}
	return n;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	for(int t=1;t<=test;++t){
		int n,q;
		cin>>n>>q;
		vector<ll> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		vector<node> tree(4*n);
		buildTree(arr,tree,0,n-1,0);
		for(int i=0;i<3*n;i++){
			cout<<tree[i].sweetness<<"\n";
		}
		ll ans = 0;
		while(q--){
			char c;
			cin>>c;
			if(c == 'Q'){
				int left,right;
				cin>>left>>right;
				node nt = query(tree,0,n-1,0,left-1,right-1);
				ans+=nt.sweetness;
			}
			else{
				int idx;
				ll value;
				cin>>idx>>value;
				updateTree(arr,tree,0,n-1,0,idx-1,value);
			}
		}
		cout<<"Case #"<<t<<":"<<" "<<ans<<"\n";
	}
	return 0;
}