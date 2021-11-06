#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1 && arr[0]%2==1){
            cout<<-1<<endl;
        }
        else{
            bool flag = false;
            for(int i=0;i<n;i++){
                if(arr[i]%2==0){
                    cout<<1<<endl;
                    cout<<(i+1)<<endl;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cout<<2<<endl;
                cout<<1<<" "<<2<<endl;
            }
        }
        delete []arr;
    }
    return 0;
}
