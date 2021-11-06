#include <iostream>
using namespace std;
int main(int argc,char const *argv[]){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool flag = true;
        int idx = -6;
        for(int i=0;i<n;i++){
            if(arr[i] == 1){
                if((i - idx)<6){
                    flag = false;
                    break;
                }
                else{
                    idx = i;
                }
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        delete []arr;
    }
    return 0;
}
