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
    if(q<0){
        while(q--){
            int left,right;
            cin>>left>>right;
            int inc_max = 0,dec_max = 0;
            int index = left-1;
            while(index<right){
                if(inc[index]!=1 && index+1<right && arr[index+inc[index]]!=arr[index+inc[index]-1] && arr[index]!=arr[index-1]){
                    //cout<<index<<endl;
                    inc_max++;
                }
                index+=inc[index];
            }
            index = left-1;
            while(index<right){
                if(dec[index]!=1 && index+1<right && arr[index+inc[index]]!=arr[index+inc[index]-1] && arr[index]!=arr[index-1]){
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
            //cout<<inc_max<<" "<<dec_max<<endl;
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
                if(arr[ind+1]!=arr[ind])
                    inc_maximal_ending_here[ind+1] = inc_maximal_ending_here[ind];
               else
                    inc_maximal_ending_here[ind+1] = inc_maximal_ending_here[ind]-1;
                ind++;
                continue;
            }
            for(long i=limit;i>ind;i--){
                inc_maximal_ending_here[i] = inc_maximal_ending_here[ind]+1;
            }
            if((limit+1)<(long)n && arr[limit+1]!=arr[limit]){
                if(arr[limit+1]!=arr[limit])
                    inc_maximal_ending_here[limit+1] = inc_maximal_ending_here[limit];
                else
                    inc_maximal_ending_here[limit+1] = inc_maximal_ending_here[limit]-1;
            }
            ind+=inc[ind];
        }
        ind = 0;
        while(ind<(long)n){
            long limit = (dec[ind]-1)+ind;
            //cout<<"index = "<<index<<"dec_limit = "<<limit<<endl;
            if(dec[ind]==1){
                if(arr[ind+1]!=arr[ind])
                    dec_maximal_ending_here[ind+1] = dec_maximal_ending_here[ind];
                else
                    dec_maximal_ending_here[ind+1] = dec_maximal_ending_here[ind]-1;
                ind++;
                continue;
            }
            for(long i=limit;i>ind;i--){
                dec_maximal_ending_here[i] = dec_maximal_ending_here[ind]+1;
            }
            if(limit+1<(long)n){
                if(arr[limit+1]!=arr[limit])
                    dec_maximal_ending_here[limit+1] = dec_maximal_ending_here[limit];
                else
                    dec_maximal_ending_here[limit+1] = dec_maximal_ending_here[limit]-1;
            }
            ind+=dec[ind];
        }
        /*for(int i=0;i<n;i++){
            cout<<inc_maximal_ending_here[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<dec_maximal_ending_here[i]<<" ";
        }
        cout<<endl;*/
        while(q--){
            int left,right;
            cin>>left>>right;
            long inc_max = inc_maximal_ending_here[right-1]-inc_maximal_ending_here[left-1],dec_max = dec_maximal_ending_here[right-1]-dec_maximal_ending_here[left-1];
            if(inc_max == 0 && inc[left-1]==(right-left)+inc[right-1]) inc_max = 1;
            if(dec_max == 0 && dec[left-1]==(right-left)+dec[right-1]) dec_max = 1;
            if(inc_max<0) inc_max = 0;
            if(dec_max<0) dec_max = 0;
            if(inc_max==dec_max){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        delete []inc_maximal_ending_here;
        delete []dec_maximal_ending_here;
    }
    delete []inc;
    delete []dec;
    delete []arr;
}
