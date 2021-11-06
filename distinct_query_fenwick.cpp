#include<bits/stdc++.h>
using namespace std;
struct event{
    int index,left,right;
};
bool compare(event x,event y){
    return x.right<y.right;
}
int query(int index,int *BIT){
    int coun = 0;
    for(;index>0;index-=(index&(-index))){
        coun+=BIT[index];
    }
    return coun;
}
void update(int index,int value,int n,int *BIT){
    for(;index<=n;index+=(index&(-index))){
        BIT[index]+=value;
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
    event *queries = new event [q];
    for(int i=0;i<q;i++){
        cin>>queries[i].left>>queries[i].right;
        queries[i].index = i;
    }
    sort(queries,queries+q,compare);
    int *BIT = new int[n+1]();
    int *ans = new int[q];
    int total = 0,k = 0;
    int *last = new int [1000001];
    for(int i=0;i<=1000000;i++){
        last[i] = -1;
    }
    for(int i=1;i<=n;i++){
        if(last[arr[i]]!=-1){
            update(last[arr[i]],-1,n,BIT);
        }
        else{
            total++;
        }
        update(i,1,n,BIT);
        last[arr[i]] = i;
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
