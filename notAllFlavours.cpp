#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        map<int,int>frequency;
        set<int>appeared;
        int curr_length = 0,max_length = 1;
        int i=0,j=0;
        while(i<n){
            if(appeared.size()!=k){
                appeared.insert(arr[i]);
                if(appeared.size()!=k){
                    curr_length++;
                    max_length = max(max_length,curr_length);
                    i++;
                    frequency[arr[i]]++;
                }
            }
            else{
                frequency[arr[j]]--;
                if(frequency[arr[j]]==0){
                    appeared.erase(arr[j]);
                }
                curr_length--;
                j++;
            }
        }
        cout<<max_length<<endl;
    }
}
