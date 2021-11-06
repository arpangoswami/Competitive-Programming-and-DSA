#include<bits/stdc++.h>
using namespace std;
int main(void){
    int coin_boxes,days,left,right;
    cin>>coin_boxes>>days;
    int *coins=new int [coin_boxes+1];
    for(int i=0;i<=coin_boxes;i++){
        coins[i]=0;
    }
    for(int i=0;i<days;i++){
        cin>>left>>right;
        coins[left-1]++;
        coins[right]--;
    }
    for(int i=1;i<coin_boxes;i++){
        coins[i]+=coins[i-1];
    }
    int maximum=INT_MIN;
    for(int i=0;i<coin_boxes;i++){
        maximum=max(coins[i],maximum);
    }
    int *prefix_end=new int [maximum+1];
    for(int i=0;i<=maximum;i++){
        prefix_end[i]=0;
    }
    for(int i=0;i<coin_boxes;i++){
        prefix_end[coins[i]]++;
    }
    for(int i=maximum-1;i>=0;i--){
        prefix_end[i]+=prefix_end[i+1];
    }
    int queries;
    cin>>queries;
    while(queries--){
        int atleast;
        cin>>atleast;
        if(atleast>maximum){
            cout<<0<<endl;
        }
        else{
            cout<<prefix_end[atleast]<<endl;
        }
    }
    delete []coins;
    delete []prefix_end;

}
