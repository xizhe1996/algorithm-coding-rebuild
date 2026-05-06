#include "leetcode_utils.h"

class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { inStack.push(x); }

  int pop() {
    int front = peek();
    outStack.pop();
    return front;
  }

  int peek() {
    if (!outStack.empty()) {
      return outStack.top();
    } else {
      while (!inStack.empty()) {
        outStack.push(inStack.top());
        inStack.pop();
      }
      return outStack.top();
    }
  }

  bool empty() { return (inStack.empty() && outStack.empty()); }

  stack<int> inStack;
  stack<int> outStack;
};

int main() { return 0; }
