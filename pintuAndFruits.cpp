/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
       int n,m;
       cin>>n>>m;
       vector<pair<int,int> >fruits;
       for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            fruits.push_back(make_pair(temp,-1));
       }
       for(int i=0;i<n;i++){
            cin>>fruits[i].second;
       }
       sort(fruits.begin(),fruits.end());
       //for(int j=0;j<n;j++){
        //cout<<fruits[j].first<<" "<<fruits[j].second<<endl;
       //}
       int cost = INT_MAX;
       int idx = 0;
       for(int i=1;i<=m;i++){
            int costFruit = 0,baskets = 0;
            while(fruits[idx].first == i){
                costFruit+=fruits[idx].second;
                baskets++;
                idx++;
            }
            if(baskets>0){
                cost = min(costFruit,cost);
            }
            //cout<<"fruit type "<<i<<" costFruit "<<costFruit<<endl;
       }
       cout<<cost<<endl;
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        int *arr1 = new int[n];
        int *arr2 = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
        }
        int miniCost = INT_MAX;
        for(int i=1;i<=m;i++){
            int costParticular = 0,basketPicked = 0;
            for(int j=0;j<n;j++){
                if(arr1[j]==i){
                    basketPicked++;
                    costParticular+=arr2[j];
                }
            }
            if(basketPicked)
            miniCost = min(miniCost,costParticular);
        }
        cout<<miniCost<<endl;
        delete []arr1;
        delete []arr2;
    }
    return 0;
}
