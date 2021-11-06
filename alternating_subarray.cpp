#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        vector<int> alter(n,1);
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            arr[i] = temp;
        }
        for(int i=n-2;i>=0;i--){
            if((long)arr[i]*(long)arr[i+1]<0){
                alter[i] = alter[i+1]+1;
            }
        }
        for(int i=0;i<n;i++){
            cout<<alter[i]<<" ";
        }
        cout<<endl;
    }
}
