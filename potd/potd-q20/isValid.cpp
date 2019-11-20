#include <string>
#include <stack>
#include <array>

using namespace std;

bool isValid(string input) {
    stack<char> st;
    for(unsigned i = 0; i < input.length(); i++) {
      if(input[i] == '(') st.push(')');
      if(input[i] == '{') st.push('}');
      if(input[i] == '[') st.push(']');
      if(input[i] == ')' || input[i] == '}' || input[i] == ']') {
        if(st.size() == 0) return false;
        if(input[i] != st.top()) return false;
        st.pop();
      }
    }
    if(st.size() != 0) return false;
    return true;    // modify this!
}
