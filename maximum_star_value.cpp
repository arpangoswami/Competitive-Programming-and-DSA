#include<bits/stdc++.h>
using namespace std;
void factors(int n,map<int,int> &freq){
    int k=1;
    while((k*k)<n){
        if((n%k)==0){
            int a=freq.count(k);
            int b=freq.count(int(n/k));
            if(a && b){
                freq[n]++;
                freq[k]++;
            }
            else if(a && !b ){
                freq.insert(pair<int,int>(n/k,1));
                freq[n]++;
            }
            else{
                freq.insert(pair<int,int>(n,1));
                freq.insert(pair<int,int>(n/k,1));
            }
        }
    }
    if((k*k)==n){
        if(freq.count(k)){
            freq[k]++;
        }
        else{
            freq.insert(pair<int,int>(k,1));
        }
    }
}
int main(void){
    int test;
    cin>>test;
    int n;
    while(test--){
        cin>>n;
        map <int,int> freq;
        int *input=new int[n];
        int max_star_value=0;
        for(int i=0;i<n;i++){
            cin>>input[i];
            int curr_star_value=0;
            int temp=freq.count(input[i]);
            if(temp){
                curr_star_value=temp;
            }
            //cout<<curr_star_value<<endl;
            factors(input[i],freq);
            max_star_value=max(curr_star_value,max_star_value);
        }

        map<int,int>::iterator itr;
        for(itr=freq.begin();itr!=freq.end();++itr)
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    cout<<max_star_value<<endl;
        delete []input;
    }
}
