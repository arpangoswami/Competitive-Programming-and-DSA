#include<stdio.h>
//using namespace std;
void Binary(int n,char *A){
    if(n < 1){
        printf("%s\n",A);
        return;
    }
    A[n-1] = '0';
    Binary(n-1,A);
    A[n-1] = '1';
    Binary(n-1,A);
}
int main(){
    char A[5];
    Binary(5,A);
    return 0;
}
