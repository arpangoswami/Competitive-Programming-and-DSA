#include<bits/stdc++.h>
#define modulo 1000000007
using namespace std;
void change_multiples(int *good_sets,int n,int size_arr){
    int i = 2*n -1;
    while(i<size_arr){
        if(good_sets[i]!=0){
            good_sets[i] = (good_sets[i]%modulo + good_sets[n-1]%modulo)%modulo;
        }
        i+=n;
    }
}
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int *arr = new int[n];
        int maximum=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(maximum<arr[i]){
                maximum = arr[i];
            }
        }
        sort(arr,arr+n);
        int *good_sets = new int[maximum]();
        for(int i=0;i<n;i++)
        {
            good_sets[arr[i]-1]=1;
        }

        for(int i=0;i<n;i++){
            change_multiples(good_sets,arr[i],maximum);
        }
        long long subsets = 0;
        for(int i=0;i<maximum;i++){
            if(good_sets[i]!=0){
                subsets=(subsets%modulo+good_sets[i]%modulo)%modulo;
            }
        }
        delete []arr;
        delete []good_sets;
        cout<<subsets%modulo<<endl;
    }
}
