#include<bits/stdc++.h>
using namespace std;
string roman(int num){
    if(num == 0){
        return "";
    }
    if(num == 4){
        return "IV";
    }
    if(num == 9){
        return "IX";
    }
    if(num>=1 && num<=3){
        return "I" + roman(num-1);
    }
    else if(num>=5 && num<9){
        return "V" + roman(num-5);
    }
    else if(num>=10 && num<40){
        return "X" + roman(num-10);
    }
    else if(num>=40 && num<50){
        return "XL" + roman(num-40);
    }
    else if(num>=50 && num<90){
        return "L" + roman(num-50);
    }
    else if(num>=90 && num<100){
        return "XC" + roman(num-90);
    }
    else if(num>=100 && num<400){
        return "C" + roman(num-100);
    }
    else if(num>=400 && num<500){
        return "CD" + roman(num-400);
    }
    else if(num>=500 && num<900){
        return "D" + roman(num-500);
    }
    else if(num>=900 && num<1000){
        return "CM" + roman(num-900);
    }
    else{
        return "M" + roman(num-1000);
    }
}
int main(void){
    cout<<roman(89)<<endl;
}
