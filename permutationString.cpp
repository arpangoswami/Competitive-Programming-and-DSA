#include<iostream>
#include<utility>
using namespace std;
int ct=1;
void permute(char s[],int index){
    if(s[index]=='\0'){
        cout<<s<<endl;
        cout<<ct<<endl;
        ct++;
        return;
    }
    for(int i=index;s[i]!='\0';i++){
        swap(s[i],s[index]);
        permute(s,index+1);
        swap(s[i],s[index]);
    }
}
int main(void){
    char s[100];
    cin>>s;
    permute(s,0);
}
