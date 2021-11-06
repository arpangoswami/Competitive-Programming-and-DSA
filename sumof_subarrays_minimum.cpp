#include<bits/stdc++.h>
using namespace std;
int findmini(const vector<int>&A,int index,int length){
        int mini = A[index];
        for(int i=index;i<length;i++){
            mini = min(A[i],mini);
        }
        return mini;
    }
int sumSubarrayMins(const vector<int>& A) {
        int size = A.size();
        int bigsize = (size*(size+1))/2;
        vector<int> minimum(bigsize,0);
        int i = 0,length = 1;
        while(i<bigsize){
            for(int j=0;j<size && (j+length)<=size;j++){
                if(j+length==size){
                    length++;
                }
                minimum[i] = findmini(A,j,length);
                i++;
            }
        }
        cout<<i<<endl;
        for(int k=0;k<bigsize;k++){
            cout<<minimum[k]<<endl;
        }
        int bigsum = 0;
        for(int x=0;x<bigsize;x++){
            bigsum += minimum[i];
            bigsum%=1000000007;
        }
        return (bigsum%1000000007);


}
int main(void){
    vector<int> A{8,5,3,1,5,6,3,4,3};
    cout<<sumSubarrayMins(A)<<endl;
}
