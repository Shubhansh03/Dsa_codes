#include<bits/stdc++.h>
using namespace std;
int pre(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    return 0;
}
string preToPost(string s) {
     stack<std::string> st;
    std::string result;

//iterate from back of given string
    for(int i=s.length()-1;i>=0;i--)
    {//if it is a char push it into the stack
        if(isalnum(s[i]))
            st.push(string(1,s[i]));
        else
        {//if operator comes then pop top of stack (let operator be /)
            string str1 = st.top(); //i.e if stack top is 'A'
            st.pop();//str1='A'
            string str2 = st.top();//let str2='B' 
            st.pop();
            result = str1 + str2 + s[i];//the finalize it to 'AB/'
            st.push(result);//ans push it to stack
        }
    }    
    return result;
}
