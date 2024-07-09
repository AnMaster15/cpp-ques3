#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int prep(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='/' || c=='*'){
        return 2;

    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else {
        return -1;
    }
}

string infixtoprefix(string s){
    stack<int>st;

    reverse(s.begin(),s.end());
    string res;

    for(int i=0;i<s.length();i++){
        char c=s[i];


        if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9' ){
            res+=c;
        }
        else if(c==')'){
            st.push(c);
        }
        else if(c=='('){
            while(!st.empty() && st.top()!=')'){
                res+=st.top();
                st.pop();
            }

            st.pop();
        }
        else{
            while(!st.empty() && prep(st.top())>=prep(c)){
                res+=st.top();
                st.pop();
            }
            st.push(c);
        }

    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;


}

int main(){

    cout<<infixtoprefix("(a-b/c)*(a/k-l)");

    return 0;
}