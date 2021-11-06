#include<bits/stdc++.h>
using namespace std;
int main(void) {
	int n;
	cin>>n;
    vector<int> seq;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        seq.push_back(temp);
    }
    int on = 0;
    int index;
    for(int i=1;i<n;i++){
        if(seq[i]>=seq[i-1]){
            on++;
            index = i;
            break;
        }
    }
    //cout<<index<<endl;
    if(on){
        for(int j=index+1;j<n;j++){
            if(seq[j]<=seq[j-1]){
                on++;
                break;
            }
        }
    }
    if(on==1 || on==0){
        cout<<"true"<<endl;
    }
    else if(on==2){
        cout<<"false"<<endl;
    }
}
