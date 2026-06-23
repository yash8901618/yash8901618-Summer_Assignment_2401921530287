
    #include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int val2 = st.top(); st.pop(); // Second operand
                int val1 = st.top(); st.pop(); // First operand
                
                if (s == "+") st.push(val1 + val2);
                else if (s == "-") st.push(val1 - val2);
                else if (s == "*") st.push(val1 * val2);
                else if (s == "/") st.push(val1 / val2);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }