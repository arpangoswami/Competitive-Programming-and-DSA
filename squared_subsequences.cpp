#include <bits/stdc++.h>
using namespace std;
void solve(){
    long n;
    cin>>n;
    long *arr = new long[n];
    for(long i=0;i<n;i++){
        cin>>arr[i];
    }
    long cnt_seq = 0;
    vector<long> multiple2;
    vector<long> multiple4;
    for(long i=0;i<n;i++){
        if(arr[i]%4 == 0){
            multiple4.push_back(i);
        }
        else if(arr[i]%2 == 0){
            multiple2.push_back(i);
        }
    }
    if(multiple2.size() == 0){
        cnt_seq = (n*(n+1))/2;
        cout<<cnt_seq<<endl;
        return;
    }
    long j = 0,k = 0,size2 = multiple2.size(),size4 = multiple4.size();
    for(long i=0;i<n;i++){
        if(arr[i]%2!=0){
            if(j<size2 && k<size4){
                if(multiple4[k]<multiple2[j]){
                    cnt_seq+=(n-i);
                }
                else{
                    cnt_seq+=(multiple2[j]-i);
                    if((j+1)<size2){
                        if(multiple4[k]<multiple2[j+1]){
                            cnt_seq+=(n-multiple4[k]);
                        }
                        else{
                            cnt_seq+=(n-multiple2[j+1]);
                        }
                    }
                    else{
                        cnt_seq+=(n-multiple4[k]);
                    }
                }
            }
            else if(j<size2 && k==size4){
                cnt_seq+=(multiple2[j]-i);
                if((j+1)<size2){
                    cnt_seq+=(n-multiple2[j+1]);
                }
            }
            else if(j==size2 && k<=size4){
                cnt_seq+=(n-i);
            }
        }
        else if(arr[i]%4 == 0){
            k++;
            cnt_seq+=(n-i);
        }
        else{
            j++;
            if(j<size2 && k<size4){
                if(multiple4[k]<multiple2[j]){
                    cnt_seq+=(n-multiple4[k]);
                }
                else{
                    cnt_seq+=(n-multiple2[j]);
                }
            }
            else if(j==size2 && k<size4){
                cnt_seq+=(n-multiple4[k]);
            }
            else if(j<size2 && k==size4){
                cnt_seq+=(n-multiple2[j]);
            }
        }
    }
    cout<<cnt_seq<<endl;
    delete []arr;
}
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}
