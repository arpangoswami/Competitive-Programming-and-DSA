#include<iostream>
#include<vector>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        int num = 0;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            arr[i] = temp+k;
            if(arr[i]%7 == 0){
                num++;
            }
        }
        cout<<num<<endl;
    }
}
