#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,p;
        cin>>n>>p;
        int *arr = new int[n];
        int *den = new int[n]();
        bool flag = false;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> factors;
        for(int i=0;i<n;i++){
            if(p%arr[i]!=0 ){
                flag = true;
                den[i] = p/arr[i] + 1;
                break;
            }
            else if(p%arr[i]==0){
                factors.push_back(arr[i]);
            }
        }
        if(!flag){
            for(int i=(n-1);i>=1;i--){
                for(int j=i-1;j>=0;j--){
                    if(arr[i]%arr[j]!=0){
                        flag = true;
                        den[i] = p/arr[i] - 1;
                        den[j] = arr[i]/arr[j]+1;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag){
                cout<<"YES"<<" ";
                for(int i=0;i<n;i++){
                    cout<<den[i]<<" ";
                }
                cout<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"YES"<<" ";
            for(int i=0;i<n;i++){
                cout<<den[i]<<" ";
            }
            cout<<endl;
        }
        delete []arr;
        delete []den;
    }
}
