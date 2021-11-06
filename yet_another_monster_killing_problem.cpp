#include<bits/stdc++.h>
using namespace std;
struct hero{
    int power,endurance;
};
bool compare(hero x,hero y){
    if(x.endurance ==  y.endurance)
        return (x.power>y.power);
    return x.endurance>y.endurance;
}
int binsearch(int *arr,int prev_index,int low,int high,int power,int endurance){
    if(target>=arr[high+1]){
        return (((high+1) - low)/endurance)+1;
    }
}
int main(void){
    int test;
    cin>>test;
    while(test--){
       int n;
       int days = 0;
       int low = 0;
       cin>>n;
       int *monster = new int [n];
       for(int i=0;i<n;i++){
           cin>>monster[i];
       }
       sort(monster,monster+n);
       int m;
       cin>>m;
       hero *super = new hero [m];
       int max_power = INT_MIN;
       for(int i=0;i<m;i++){
        cin>>super[i].power>>super[i].endurance;
        max_power = max(super[i].power,max_power);
       }
       if(max_power<monster[n-1]){
        cout<<-1<<endl;
        continue;
       }
       sort(super,super+m,compare);
       for(int i=0;i<m;){
        int endindex = i;
        while(endindex<m && (super[i].power >=super[endindex].power)){
            endindex++;
        }
        int ans = binsearch(monster,prev_index,low,n-1,super[i].power,super[i].endurance);
        low+=ans;
        i = endindex;
       }
       cout<<ans<<endl;
    }
}
