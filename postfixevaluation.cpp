#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int postfixevaluation(string s){
    stack<int>st;

    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c>='0' && c<='9'){
            st.push(c-'0');//ascii value minus karke integer value
        }
        else{
            int ans2=st.top();
            st.pop();
             int ans1=st.top();
            st.pop();

            switch(c){
                case '+':
                    st.push(ans1+ans2);
                    break;

                case '-':
                    st.push(ans1-ans2);
                    break;

                case '*':
                    st.push(ans1*ans2);
                    break;

                case '/':
                    st.push(ans1/ans2);
                    break;

                case '^':
                    st.push(pow(ans1,ans2));
                    break;

                
            }
        }
    }
    return st.top();
}
int main(){

    cout<<postfixevaluation("452-5862/+4-*-3-");

    return 0;
}
//46+2/5*7+