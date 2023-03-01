#include <iostream>
#include <string>
#include <stack>

bool isValid(std::string s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                return false;
            }
            st.pop();
        } else if (c == '}') {
            if (st.empty() || st.top() != '{') {
                return false;
            }
            st.pop();
        } else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

bool isValid_myImplementation(std::string s) {
    std::stack<char> st;

    for ( char c : s ) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')'){
            if(st.empty() || st.top() != '(') {
                return false;
            }
            st.pop();
        } else if (c == ']'){
            if(st.empty() || st.top() != '[') {
                return false;
            }
            st.pop();
        } else if (c == '}'){
            if(st.empty() || st.top() != '{') {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
void iterateString(std::string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        std::cout << c << std::endl;
    }
}