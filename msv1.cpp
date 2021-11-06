#include<bits/stdc++.h>
using namespace std;
void factors(int n,int freq[]){
    int k=1;
    while((k*k)<n){
        if((n%k)==0){
            ++freq[(k-1)];
            ++freq[((n/k)-1)];
        }
        ++k;
    }
    if((k*k)==n){
        ++freq[k-1];
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
        int maximum=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>input[i];
            maximum=max(maximum,input[i]);
        }
        int *freq=new int[maximum]();
        for(int i=0;i<n;i++){
            int curr_star_value=freq[(input[i]-1)];
            //cout<<curr_star_value<<endl;
            factors(input[i],freq);
            max_star_value=max(curr_star_value,max_star_value);
        }
        cout<<max_star_value<<endl;
        delete []input;
        delete []freq;
    }
}
