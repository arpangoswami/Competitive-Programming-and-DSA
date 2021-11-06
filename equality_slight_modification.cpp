#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n,q;
    cin>>n>>q;
    int *arr = new int[n],*inc = new int[n](),*dec = new int[n]();
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        inc[i] = 1;
        dec[i] = 1;
    }
    int index = 0;
    while(index<n){
        int len = 1;
        for(int i=index+1;i<n;i++){
            if(arr[i]>arr[i-1]){
                len++;
            }
            else{
                break;
            }
        }
        inc[index] = len;
        int temp = len;
        for(int i=index+1;i<index+len;i++){
            inc[i] = --temp;
        }
        index+=len;
    }
    index = 0;
    while(index<n){
        int len = 1;
        for(int i=index+1;i<n;i++){
            if(arr[i]<arr[i-1]){
                len++;
            }
            else{
                break;
            }
        }
        dec[index] = len;
        int temp = len;
        for(int i=index+1;i<index+len;i++){
            dec[i] = --temp;
        }
        index+=len;
    }
    if(q<1000){
        while(q--){
            int left,right;
            cin>>left>>right;
            int inc_max = 0,dec_max = 0;
            int index = left-1;
            while(index<right){
                if(inc[index]!=1 && index+1<right){
                    inc_max++;
                }
                index+=inc[index];
            }
            index = left-1;
            while(index<right){
                if(dec[index]!=1 && index+1<right){
                    dec_max++;
                }
                index+=dec[index];
            }
            if(inc_max==dec_max){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }

    else{
        long *inc_maximal_ending_here = new long[n]();
        long *dec_maximal_ending_here = new long[n]();
        long ind = 0;
        while(ind<(long)n){
            long limit = (inc[ind]-1)+ind;
            //cout<<"index = "<<index<<"inc_limit = "<<limit<<endl;
            if(inc[ind]==1){
                inc_maximal_ending_here[ind+1] = inc_maximal_ending_here[ind];
                ind++;
                continue;
            }
            for(long i=limit;i>ind;i--){
                inc_maximal_ending_here[i] = inc_maximal_ending_here[ind]+1;
            }
            if((limit+1)<(long)n)
                inc_maximal_ending_here[limit+1] = inc_maximal_ending_here[limit];
            ind+=inc[ind];
        }
        ind = 0;
        while(ind<(long)n){
            long limit = (dec[ind]-1)+ind;
            //cout<<"index = "<<index<<"dec_limit = "<<limit<<endl;
            if(dec[ind]==1){
                dec_maximal_ending_here[ind+1] = dec_maximal_ending_here[ind];
                ind++;
                continue;
            }
            for(long i=limit;i>ind;i--){
                dec_maximal_ending_here[i] = dec_maximal_ending_here[ind]+1;
            }
            if(limit+1<(long)n)
                dec_maximal_ending_here[limit+1] = dec_maximal_ending_here[limit];
            ind+=dec[ind];
        }
        while(q--){
            int left,right;
            cin>>left>>right;
            long inc_max = inc_maximal_ending_here[right-1]-inc_maximal_ending_here[left-1],dec_max = dec_maximal_ending_here[right-1]-dec_maximal_ending_here[left-1];
            if(inc_max == 0 && inc[left-1]>inc[right-1]) inc_max = 1;
            if(dec_max == 0 && dec[left-1]>dec[right-1]) dec_max = 1;
            if(inc_max==dec_max){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
    }
    /*for(int i=0;i<n;i++){
        cout<<inc[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<dec[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<inc_maximal_ending_here[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<dec_maximal_ending_here[i]<<" ";
    }
    cout<<endl;*/
    delete []inc_maximal_ending_here;
    delete []dec_maximal_ending_here;
}
    delete []inc;
    delete []dec;
    delete []arr;
}
