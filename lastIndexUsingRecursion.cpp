#include<iostream>
using namespace std;
int lastIndex(int arr[],int n,int index,int last,int fin){
    if(n==0) return last;
    if(arr[0] == fin) last = index;
    return lastIndex(arr+1,n-1,index+1,last,fin);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int fin;
    cin>>fin;
    int index = lastIndex(arr,n,0,-1,fin);
    cout<<index;
	return 0;
}
