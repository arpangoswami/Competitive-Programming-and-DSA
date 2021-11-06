#include<iostream>
using namespace std;
void Binary(int n,int *A){
    if(n < 1){
        for(int i=4;i>=0;i--){
            cout<<A[i];
        }
        cout<<endl;
        return;
    }
    A[n-1] = 0;
    Binary(n-1,A);
    A[n-1] = 1;
    Binary(n-1,A);
}
int main(void){
    int A[5]={0,0,0,0,0};
    Binary(5,A);
}
