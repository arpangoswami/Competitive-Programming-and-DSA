#include<bits/stdc++.h>
using namespace std;
int main() {
	while(true){
		char c;
		cin>>c;
		int num1,num2;
		switch(c){
			case '+':
			    cin>>num1>>num2;
				cout<<(num1+num2)<<endl;
				break;
			case '-':
			    cin>>num1>>num2;
				cout<<(num1-num2)<<endl;
				break;
			case '*':
			    cin>>num1>>num2;
				cout<<(num1*num2)<<endl;
				break;
			case '/':
			    cin>>num1>>num2;
				cout<<(num1/num2)<<endl;
				break;
			case '%':
			    cin>>num1>>num2;
				cout<<(num1%num2)<<endl;
				break;
			case 'x':
				exit(0);
			case 'X':
				exit(0);
			default:
				cout<<"Invalid operation. Try again."<<endl;
				break;
		}
	}
	return 0;
}
