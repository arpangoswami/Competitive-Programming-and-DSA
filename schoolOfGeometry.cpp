#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int *a = new int[n];
        int *b = new int[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        long sumOfDiameters = 0;
        sort(a,a+n);
        sort(b,b+n);
        for(int i=0;i<n;i++){
            sumOfDiameters+=long(min(a[i],b[i]));
        }
        cout<<sumOfDiameters<<endl;
        delete []a;
        delete []b;
    }
}
