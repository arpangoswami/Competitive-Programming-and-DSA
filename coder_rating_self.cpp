#include<bits/stdc++.h>
using namespace std;
struct coder{
    int open,high,index;
};
bool compare(coder X,coder Y){
    if(X.open == Y.open){
        return X.high<Y.high;
    }
    return X.open<Y.open;
}
void update(int y,int n,int *BIT){
    for(;y<=n;y+=(y&(-y))){
        BIT[y]++;
    }
}
int query(int y,int *BIT){
    int coun = 0;
    for(;y>0;y-=(y&(-y))){
        coun+=BIT[y];
    }
    return coun;
}
int main(void){
    int n;
    cin>>n;
    coder *arr = new coder [n]();
    int max_y = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i].open>>arr[i].high;
        arr[i].index = i;
        max_y = max(max_y,arr[i].high);
    }
    sort(arr,arr+n,compare);
    int *BIT = new int [max_y+1]();
    int *ans = new int[n];
    for(int i=0;i<n;){
        int endindex = i;
        while( endindex<n && (arr[i].open == arr[endindex].open && arr[i].high == arr[endindex].high) )
            endindex++;
        for(int j=i;j<endindex;j++){
            ans[arr[j].index] = query(arr[j].high,BIT);
        }
        for(int j = i;j<endindex;j++){
            update(arr[j].high,max_y,BIT);
        }
        i = endindex;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<"\n";
    }
    delete []BIT;
    delete []arr;
    delete []ans;

}
