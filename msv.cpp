#include<bits/stdc++.h>
using namespace std;
int *freq=new int[100000]();
void factors(int n){
    int k=1;
    while((k*k)<n){
        if((n%k)==0){
            freq[k-1]++;
            freq[(n/k)-1]++;
        }
    }
    if((k*k)==n){
        freq[k-1]++;
    }
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int *input=new int[n];
        int max_star_value=0;
        for(int i=0;i<n;i++){
            cin>>input[i];
            int curr_star_value=0;
            int temp=freq[input[i]-1];
            if(temp){
                curr_star_value=temp;
            }
            //cout<<curr_star_value<<endl;
            factors(input[i]);
            max_star_value=max(curr_star_value,max_star_value);
            cout<<curr_star_value<<endl;
        }
        cout<<max_star_value<<endl;
        delete []input;
        for(int i=0;i<n;i++){
            freq[i]=0;
        }
    }
}
