#include<stdio.h>
#include<stdlib.h>
#define sizearr 100001
int main(){
    int n,i,j,left,right;
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int)*sizearr);
    for(i=0;i<sizearr;i++){
        arr[i] = 1;
    }
    arr[0] = 0;
    arr[1] = 0;
    for(i=4;i<sizearr;i+=2){
        arr[i] = 0;
    }
    for(i=3;i<sizearr;i+=2){
        if(arr[i] == 0){
            continue;
        }
        else{
            for(j=i*i;j<sizearr;j+=i){
                arr[j] = 0;
            }
        }
    }
    for(i=2;i<sizearr;i++){
        arr[i]+=arr[i-1];
    }

    while(n--){
        int left,right;
        scanf("%d%d",&left,&right);
        int prime = arr[right]-arr[left-1];
        printf("%d",prime);
    }
    free(arr);
    return 0;
}
