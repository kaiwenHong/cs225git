#include "Stack.h"

// `int size()` - returns the number of elements in the stack (0 if empty)
int Stack::size() const {
  return mystack.size();
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Stack::isEmpty() const {
  return mystack.empty();
}

// `void push(int val)` - pushes an item to the stack in O(1) time
void Stack::push(int value) {
  mystack.push(value);
}

// `int pop()` - removes an item off the stack and returns the value in O(1) time
int Stack::pop() {
  int result = mystack.top();
  mystack.pop();
  return result;
}
