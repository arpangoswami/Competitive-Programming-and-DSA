#include<iostream>
using namespace std;
int arr[1000001];
void gen_primes(){
	for(unsigned i=3; i<=1000000; i+=2){
		arr[i]=1;
	}
	arr[0]=0;
	arr[1]=0;
	arr[2]=1;
	for(unsigned i=2;i*i<=1000000;i++){
		if(arr[i]==1){
			for(unsigned j=i*i;j<=1000000;j+=i) arr[j]=0;
		}
	}
	for(unsigned i=2;i<=1000000;i++){
        arr[i]+=arr[i-1];
	}
}
int main() {
  int t;
  cin>>t;
  gen_primes();
  while (t--) {
    int a, b;
    cin>>a>>b;
    cout<<arr[b]-arr[a-1]<<endl;
  }
  return 0;
}
