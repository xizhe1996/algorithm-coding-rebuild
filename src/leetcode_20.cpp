#include "leetcode_utils.h"

class Solution {
 public:
  bool isVaild(string s) {
    stack<char> st;
    for (const char& c : s) {
      switch (c) {
        case '{':
          st.push('}');
          break;
        case '[':
          st.push(']');
          break;
        case '(':
          st.push(')');
          break;

        case '}':
        case ']':
        case ')':
          if (!st.empty() && st.top() == c)
            st.pop();
          else
            return false;
          break;

        default:
          return false;
          break;
      }
    }

    return st.empty();
  }
};

int main() { return 0; }