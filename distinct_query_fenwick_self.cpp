#include<bits/stdc++.h>
using namespace std;
struct event{
    int left,right,index;
};
bool compare(query X,query Y){
    return X.right<Y.right;
}
int query(int i,int *BIT){
    int coun = 0;
    for(;i>0;i-=(i&(-i))){
        coun+=BIT[i];
    }
    return coun;
}
void update(int i,int n,int val,int *BIT){
    for(;i<=n;i+=(i&(-i))){
        BIT[i]+=val;
    }
}
int main(void){
    int n;
    cin>>n;
    int *arr = new int[n+1]();
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int q;
    cin>>q;
    event *store_query = new event[q];
    int *ans = new int[q];
    for(int i =0;i<q;i++){
        cin>>store_query[i].left>>store_query[i].right;
        store_query[i].index = i;
    }
    sort(store_query,store_query+q,compare);
    int *last_index = new int[1000001],total = 0,k = 0;
    int *BIT = new int[n+1]();
    for(int i=0;i<=1000000;i++){
        last_index[i] = -1;
    }
    for(int i=1;i<=n;i++){
        if(last_index[arr[i]]!=-1){
            update(last[arr[i]],-1,n,BIT);
        }
        else{
            total++;
        }
        update(i,1,n,BIT);
        last_index[arr[i]] = i;
        while(k<q && (queries[k].right == i)){
            ans[queries[k].index] = total - query(queries[k].left-1,BIT);
            k++;
        }
    }
    for(int i = 0;i<q;i++){
        cout<<ans[i]<<"\n";
    }
    delete []queries;
    delete []arr;
    delete []BIT;
    delete []last;
    delete []ans;

}
