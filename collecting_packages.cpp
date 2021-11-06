#include<bits/stdc++.h>
using namespace std;
struct package_loc{
    int x,y;
};
bool compare(package_loc A,package_loc B){
    if(A.x==B.x) return A.y<B.y;
    return A.x<B.x;
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        package_loc *arr = new package_loc[n];
        for(int i=0;i<n;i++){
            cin>>arr[i].x>>arr[i].y;
        }
        sort(arr,arr+n,compare);
        string ans="";
        bool flag = true;
        for(int i=0;i<n;i++){
            int right = arr[i].x;
            int up = arr[i].y;
            for(int j=0;j<right;j++){
                ans+="R";
            }
            for(int j=0;j<up;j++){
                ans+="U";
            }
            for(int j=i+1;j<n;j++){
                arr[j].x -=right;
                arr[j].y -=up;
                if((arr[j].x<0)||(arr[j].y<0)){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        if(!flag) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }
    }
}
