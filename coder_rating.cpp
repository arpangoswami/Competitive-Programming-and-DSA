#include<bits/stdc++.h>
using namespace std;
struct coder{
    int index;
    int open;
    int high;
};
int total = 9;
bool compare(coder x,coder y){
    if(x.open==y.open)
        return (x.high<y.high);
    return (x.open<y.open);
}
int query(int i,int *BIT){
    int coun = 0;
    while(i>0){
        coun+=BIT[i];
        i-=(i&(-i));
    }
    return coun;
}
void update(int i,int *BIT){
    while(i<=100000){
        BIT[i]++;
        i+=(i&(-i));
    }
    // for(int i=1;i<=8;i++){
    //     cout<<BIT[i]<<" ";
    // }
    //cout<<endl;
}
int main(void){
    int n;
    cin>>n;
    coder *arr = new coder [n]();
    for(int i=0;i<n;i++){
        cin>>arr[i].open>>arr[i].high;
        arr[i].index = i;
    }
    sort(arr,arr+n,compare);
    int *BIT = new int [100001]();
    int *ans = new int[n];
    for(int i=0;i<n;){
        int endindex = i;
        while( endindex<n && (arr[i].open == arr[endindex].open && arr[i].high == arr[endindex].high) )
            endindex++;
        for(int j=i;j<endindex;j++){
            ans[arr[j].index] = query(arr[j].high,BIT);
        }
        for(int j = i;j<endindex;j++){
            update(arr[j].high,BIT);
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
