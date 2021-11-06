#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
class Triplet{
public:
    long long x;
    long long y;
    long long gcd;
};
class expression{
public:
    char ch;
    long long p;
    long long q;
    expression(){
        ch = '\0';
        p = 0;
        q = 0;
    }
    expression(char ch){
        this->ch = ch;
        p = 1;
        q = 4;
    }
};
Triplet extendedEuclid(long long a,long long b){
    if(b == 0){
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    Triplet ans,smallAns = extendedEuclid(b,a%b);
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}
long long mmInverse(long long a,long long b = 998244353){
    long long ans = extendedEuclid(a,b).x;
    if(ans<0){
        return ans+mod;
    }
    return ans%mod;
}
vector<expression> ORoperation(vector<expression> e1,vector<expression> e2){
    //exp1,exp5 = 0
    //exp2,exp6 = 1
    //exp3,exp7 = a
    //exp4,exp8 = A
    expression exp1 = e1[0],exp2 = e1[1],exp3 = e1[2],exp4 = e1[3],exp5 = e2[0],exp6 = e2[1],exp7 = e2[2],exp8 = e2[3];
    vector<expression> ans;
    expression ans0,ans1,ans_a,ans_A;
    ans0.ch = '0';
    ans0.p = (exp1.p%mod * exp5.p%mod)%mod;
    //0 | 0 = 0
    ans0.q = (exp1.q%mod * exp5.q%mod)%mod;
    ans1.ch = '1';
    ans1.p = ((exp1.p%mod * exp6.p%mod)%mod+(exp2.p%mod * exp5.p%mod)%mod + (exp2.p%mod * exp6.p%mod)%mod + (exp2.p%mod * exp7.p%mod)%mod + (exp2.p%mod * exp8.p%mod)%mod + (exp3.p%mod * exp6.p%mod)%mod + (exp4.p%mod * exp6.p%mod)%mod + (exp3.p%mod * exp8.p%mod)%mod + (exp4.p%mod * exp7.p%mod)%mod)%mod;
    // 0 | 1 = 1, 1|0 = 1,1|1 = 1,1|a = 1,1|A = 1,a|1 = a,A|1 = 1,a|A = 1,A|a = 1
    ans1.q = (exp1.q%mod * exp5.q%mod)%mod;
    ans_a.ch = 'a';
    ans_a.p = ((exp1.p%mod * exp7.p%mod)%mod + (exp3.p%mod * exp5.p%mod)%mod + (exp3.p%mod * exp7.p%mod)%mod)%mod;
    //0|a = a,a|0 = a,a|a = a
    ans_a.q = (exp1.q%mod * exp5.q%mod)%mod;
    ans_A.ch = 'A';
    ans_A.p = ((exp1.p%mod * exp7.p%mod)%mod + (exp3.p%mod * exp5.p%mod)%mod + (exp3.p%mod * exp7.p%mod)%mod)%mod;
    //0|A = A,A|0 = A,A|A = A
    ans_A.q = (exp1.q%mod * exp5.q%mod)%mod;
    ans.push_back(ans0);
    ans.push_back(ans1);
    ans.push_back(ans_a);
    ans.push_back(ans_A);
    return ans;
}
vector<expression> ANDoperation(vector<expression> e1,vector<expression> e2){
    //exp1,exp5 = 0
    //exp2,exp6 = 1
    //exp3,exp7 = a
    //exp4,exp8 = A
    expression exp1 = e1[0],exp2 = e1[1],exp3 = e1[2],exp4 = e1[3],exp5 = e2[0],exp6 = e2[1],exp7 = e2[2],exp8 = e2[3];
    vector<expression> ans;
    expression ans0,ans1,ans_a,ans_A;
    ans0.ch = '0';
    //0&0 = 0,0&1 = 0,0&a = 0,0&A = 0,1&0 = 0,a&0 = 0,A&0 = 0,a&A = 0,A&a = 0
    ans0.p = ((exp1.p%mod * exp5.p%mod)%mod + (exp1.p%mod * exp6.p%mod)%mod + (exp1.p%mod * exp7.p%mod)%mod + (exp1.p%mod * exp8.p%mod)%mod + (exp2.p%mod * exp5.p%mod)%mod+(exp3.p%mod * exp5.p%mod)%mod + (exp4.p%mod * exp5.p%mod)%mod + (exp3.p%mod * exp8.p%mod)%mod + (exp4.p%mod * exp7.p%mod)%mod)%mod;
    ans0.q = (exp1.q%mod * exp5.q%mod)%mod;
    ans1.ch = '1';
    ans1.p = (exp2.p%mod * exp6.p%mod)%mod;
    ans1.q = (exp1.q%mod * exp5.q%mod)%mod;
    //1&1 = 1
    ans_a.ch = 'a';
    ans_a.p = ((exp2.p%mod * exp7.p%mod)%mod + (exp3.p%mod * exp6.p%mod)%mod + (exp3.p%mod * exp7.p%mod)%mod)%mod;
    //1&a = a,a&1 = a,a&a = a;
    ans_a.q = (exp1.q%mod * exp5.q%mod)%mod;
    ans_A.ch = 'A';
    ans_A.p = ((exp2.p%mod * exp8.p%mod)%mod + (exp4.p%mod * exp6.p%mod)%mod + (exp4.p%mod * exp8.p%mod)%mod)%mod;
    //1&A = A,A&1 = A,A&A = A
    ans_A.q = (exp1.q%mod * exp5.q%mod)%mod;
    ans.push_back(ans0);
    ans.push_back(ans1);
    ans.push_back(ans_a);
    ans.push_back(ans_A);
    return ans;
}
vector<expression> XORoperation(vector<expression> e1,vector<expression> e2){
    //exp1,exp5 = 0
    //exp2,exp6 = 1
    //exp3,exp7 = a
    //exp4,exp8 = A
    expression exp1 = e1[0],exp2 = e1[1],exp3 = e1[2],exp4 = e1[3],exp5 = e2[0],exp6 = e2[1],exp7 = e2[2],exp8 = e2[3];
    vector<expression> ans;
    expression ans0,ans1,ans_a,ans_A;
    ans0.ch = '0';
    ans0.p = ((exp1.p%mod * exp5.p%mod)%mod + (exp2.p%mod * exp6.p%mod)%mod + (exp3.p%mod * exp7.p%mod)%mod + (exp4.p%mod * exp8.p)%mod)%mod;
    // 0^0 = 0,1^1 = 1,a^a = 0,A^A=0
    ans0.q = (exp1.q%mod * exp5.q%mod)%mod;
    ans1.ch = '1';
    ans1.p = ((exp2.p%mod * exp5.p%mod)%mod + (exp1.p%mod * exp6.p%mod) + (exp3.p%mod * exp8.p%mod) + (exp4.p%mod * exp7.p%mod))%mod;
    // 1^0 = 1, 0^1 = 1,a^A = 1,A^a = 1
    ans1.q = (exp1.q%mod * exp5.q%mod)%mod;
    ans_a.ch = 'a';
    ans_a.p = ((exp1.p%mod * exp7.p%mod)%mod + (exp2.p%mod * exp8.p%mod)%mod + (exp3.p%mod * exp5.p%mod)%mod + (exp4.p%mod * exp6.p%mod)%mod)%mod;
    //0^a = a,1^A = a,a^0 = a,A^1 = a
    ans_a.q = (exp1.q%mod * exp5.q%mod)%mod;
    ans_A.ch = 'A';
    ans_A.p = ((exp1.p%mod * exp8.p%mod)%mod + (exp2.p%mod * exp7.p%mod)%mod + (exp3.p%mod * exp6.p%mod)%mod + (exp4.p%mod * exp5.p%mod)%mod)%mod;
    //0^A = A,1^a = A,a^1 = A,A^0 = A
    ans_A.q = (exp1.q%mod * exp5.q%mod)%mod;
    ans.push_back(ans0);
    ans.push_back(ans1);
    ans.push_back(ans_a);
    ans.push_back(ans_A);
    return ans;
}
string infix_to_postfix(const string &infix){
    long long n = infix.size();
    string postfix;
    stack<char> st;
    for(long long i=0;i<n;i++){
        char symbol = infix[i];
        if(symbol == '('){
            st.push(symbol);
        }else if(symbol=='#'){
            postfix.push_back(symbol);
        }
        else if(symbol == '|' || symbol == '&' || symbol == '^'){
            st.push(symbol);
        }
        else{
            while(st.top()!='('){
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
    }
    return postfix;
}
int main(int argc,char const* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test;
    cin>>test;
    while(test--){
        string infix;
        cin>>infix;
        string postfix = infix_to_postfix(infix);
        stack<vector<expression> >prob;
        for(int i=0;i<postfix.size();i++){
            if(postfix[i] == '#'){
                vector<expression> temp;
                expression e1 = expression('0');
                temp.push_back(e1);
                expression e2 = expression('1');
                temp.push_back(e2);
                expression e3 = expression('a');
                temp.push_back(e3);
                expression e4 = expression('A');
                temp.push_back(e4);
                prob.push(temp);
            }
            else if(postfix[i] == '|'){
                vector<expression> temp1 = prob.top();
                prob.pop();
                vector<expression> temp2 = prob.top();
                prob.pop();
                vector<expression> temp3 = ORoperation(temp1,temp2);
                prob.push(temp3);
            }
            else if(postfix[i] == '&'){
                vector<expression> temp1 = prob.top();
                prob.pop();
                vector<expression> temp2 = prob.top();
                prob.pop();
                vector<expression> temp3 = ANDoperation(temp1,temp2);
                prob.push(temp3);
            }
            else if(postfix[i] == '^'){
                vector<expression> temp1 = prob.top();
                prob.pop();
                vector<expression> temp2 = prob.top();
                prob.pop();
                vector<expression> temp3 = XORoperation(temp1,temp2);
                prob.push(temp3);
            }
        }
        vector<expression> temp = prob.top();
        prob.pop();
        long long gc1 = __gcd(temp[0].p,temp[0].q),gc2 = __gcd(temp[1].p,temp[1].q),gc3 = __gcd(temp[2].p,temp[2].q),gc4 = __gcd(temp[3].p,temp[3].q);
        temp[0].p/=gc1;
        temp[0].q/=gc1;
        temp[1].p/=gc2;
        temp[1].q/=gc2;
        temp[2].p/=gc3;
        temp[2].q/=gc3;
        temp[3].p/=gc4;
        temp[3].q/=gc4;
        //cout<<(temp[0].p) <<" "<<(temp[0].q)<<" "<<(temp[1].p)<<" "<<temp[1].q<<" "<<temp[2].p<<" "<<temp[2].q<<" "<<temp[3].p<<" "<<temp[3].q<<endl;
        cout<<((temp[0].p)%mod * mmInverse(temp[0].q%mod)%mod)%mod<<" "<<((temp[1].p)%mod * mmInverse(temp[1].q%mod)%mod)%mod<<" "<<((temp[2].p)%mod * mmInverse(temp[2].q%mod)%mod)%mod<<" "<<((temp[3].p)%mod * mmInverse(temp[3].q%mod)%mod)%mod<<endl;
    }
    return 0;
}
