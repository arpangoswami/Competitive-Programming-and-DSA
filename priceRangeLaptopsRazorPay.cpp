/*
5
1000 300
1100 400
1300 200
1700 500
2000 600
3
1000 1400
1700 1900 
0 2000
*/
#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<int> tree;
void buildTree(vector<int> &arr,int start,int finish,int treeNode){
    if(start==finish){
        tree[treeNode]=arr[start];
        return;
    }
    int mid=(start+finish)/2;
    buildTree(arr,start,mid,2*treeNode);
    buildTree(arr,mid+1,finish,2*treeNode+1);
    tree[treeNode]=max(tree[2*treeNode],tree[2*treeNode+1]);
}
int query(int start,int finish,int treeNode,int left,int right){
    if(start>right || finish<left){
        return 0;
    }
    else if(start>=left && finish<=right){
        return tree[treeNode];
    }
    int mid=(start+finish)/2;
    int ans1=query(start,mid,2*treeNode,left,right);
    int ans2=query(mid+1,finish,2*treeNode+1,left,right);
    return max(ans1,ans2);
}

void solveQuestion(){
	int n;
	cin >> n;
	vector<pii> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].ff >> arr[i].ss;
	}
	sort(arr.begin(),arr.end());
	map<int,int> mp;
	for(int i=0;i<n;i++){
		mp[arr[i].ff] = i;
	}
	vector<int> ratings(n);
	for(int i=0;i<n;i++){
		ratings[i] = arr[i].ss;
	}
	tree.resize(4*n);
	buildTree(ratings,0,n-1,1);
	int q;
	cin >> q;
	while(q-- > 0){
		int x,y;
		cin >> x >> y;
		auto it1 = mp.lower_bound(x);
		auto it2 = mp.upper_bound(y);
		it2--;
		int idx1 = it1 == mp.end() ? n : (*it1).second;
		int idx2 = (*it2).second;
		if(idx1 > idx2){
			cout<<"-1\n";
			continue;
		}
		cout << query(0,n-1,1,idx1,idx2) << "\n"; 
	}
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