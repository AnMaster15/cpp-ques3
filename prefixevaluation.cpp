#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int prefixevaluation(string s){
    stack<int>st;

    for(int i=s.length()-1;i>=0;i--){
        char c=s[i];
        if(c>='0' && c<='9'){
            st.push(c-'0');//ascii value minus karke integer value
        }
        else{
            int ans1=st.top();
            st.pop();
             int ans2=st.top();
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

    cout<<prefixevaluation("-+7*45+20");

    return 0;
}