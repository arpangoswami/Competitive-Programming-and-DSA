#include<bits/stdc++.h>
using namespace std;
int main(void){
    int test;
    cin>>test;
    while(test--){
        int m,n;
        cin>>n>>m;
        int **arr = new int*[n],**solution = new int*[n];
        for(int i=0;i<n;i++){
            arr[i] = new int[m];
            solution[i] = new int[m];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int left = j,right = j,up = i,down = i;
                while(left>=0 && right<m && up>=0 && down<n && arr[i][left]==arr[i][right] && arr[up][j] == arr[down][j]){
                    solution[i][j] = right - left + 1;
                    left--;
                    right++;
                    up--;
                    down++;
                }
            }
        }
        long long total = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total+=((solution[i][j]+1)/2);
            }
        }
        cout<<total<<endl;
        for(int i=0;i<n;i++){
            delete []arr[i];
            delete []solution[i];
        }
        delete []arr;
        delete []solution;
    }
}
