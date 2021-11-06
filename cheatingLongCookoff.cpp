#include<bits/stdc++.h>
using namespace std;
bool checkLeap(int year){
    if((year%400)==0) return true;
    if((year%100)==0) return false;
    if((year%4)==0) return true;
    return false;
}
int determineDay(int date,int month,int year){
    int day_index[12] = {0,3,2,5,0,3,5,1,4,6,2,4};
    if(month<=2){
        year--;
    }
    return (year + year/4 + year/400 - year/100 + day_index[month-1] + date)%7;
}
int calculateHowMany(int m1,int m2,int y1,int y2){
    int i = y1,ans=0,day;
    while(i <= y2)
    {
        if(checkLeap(i))                             // leap year
        {
            day = determineDay(7,2,i);
            if(day == 5)
            {
                ans++;
            }
        }
        else
        {
            day = determineDay(7,2,i);
            if(day == 5 || day == 6)
            {
                ans++;
            }
        }
        i++;
    }
    return ans;
}
int main(void){
    int test;
    cin>>test;
    while(test--)
    {
        int m1,m2,y1,y2,i,c=0,day,y2modified,A,B,N=0;
        cin>>m1>>y1;
        cin>>m2>>y2;
        if(m1>2)
        {
            y1++;
        }
        m1 = 2;
        if(m2<2)
        {
            y2--;
        }
        m2 = 2;
        if((y2-y1<400))
        {
            c = calculateHowMany(m1,m2,y1,y2);
        }
        else
        {
            A=y2-y1;
            B = A/400;
            A = A%400;
            y2modified=y1+A;
            c = calculateHowMany(m1,m2,y1,y2modified);
            N = calculateHowMany(m2,m2,y2modified+1,y2modified+400);
            c=c+(N*B);
        }
        cout<<c<<endl;
    }
    return 0;
}
