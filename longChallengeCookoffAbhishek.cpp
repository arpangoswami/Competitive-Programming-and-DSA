#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll leap(ll);

ll dayofweek(ll d, ll m, ll y)
{
    static ll t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

ll Calculate(ll m1, ll m2, ll y1, ll y2)
{
    ll i,c=0,day;
    i = y1;
    while(i <= y2)
    {
        if(leap(i))                             // leap year
        {
            day = dayofweek(7,2,i);
            if(day == 5)
            {
                //cout<<i<<endl;
                c++;
            }
        }
        else
        {
            day = dayofweek(7,2,i);
            if(day == 5 || day == 6)
            {
                //cout<<i<<endl;
                c++;
            }
        }
        i++;
    }
    return c;
}

ll leap(ll year)
{
     if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
     {
         return 1;
     }
     else
     {
         return 0;
     }
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll m1,m2,y1,y2,i,c=0,day,Y2,A,B,N=0;
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
            c = Calculate(m1,m2,y1,y2);
        }
        else
        {
            A=y2-y1;
            B = A/400;
            A = A%400;
            Y2=y1+A;
            c = Calculate(m1,m2,y1,Y2);
            N = Calculate(m2,m2,Y2+1,Y2+400);
            c=c+(N*B);
        }
        cout<<c<<endl;
    }
    return 0;
}
