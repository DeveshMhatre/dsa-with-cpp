#include <iostream>

#include "dbg.h"

#define MAX_SIZE 4

using namespace std;

class Stack {
private:
  int *arr;
  int size;
  int top;

  int *create() {
    int *array = (int *)malloc(sizeof(int) * size);
    check_mem(arr);

    log_info("Stack Created");
    return array;

  error:
    exit(1);
  }

public:
  Stack(int capacity) {
    size = capacity;
    top = -1;
    arr = create();
  }

  int get_size() { return size; }

  int get_top() { return top; }

  int is_empty() {
    if (top == -1) {
      return 1;
    }

    return 0;
  }

  int is_full() {
    if (top == size - 1) {
      return 1;
    }

    return 0;
  }

  int peek() {
    if (is_empty() == 1) {
      log_err("Stack underflow!");
      return -1;
    }

    return arr[top];
  }

  void push(int element) {
    if (is_full() == 1) {
      log_err("Stack overflow!");
      return;
    }

    top += 1;
    arr[top] = element;
  }

  int pop() {
    if (is_empty() == 1) {
      log_err("Stack underflow!");
      return -1;
    }

    int popped = peek();
    top -= 1;
    return popped;
  }

  void kill() {
    check_mem(arr);
    free(arr);
    log_info("Stack Freed");

  error:
    exit(1);
  }
};

int main(int argc, char *argv[]) {
  Stack stack(MAX_SIZE);

  stack.push(53);
  stack.push(3);
  stack.push(48);
  stack.push(19);
  cout << "Element at top: " << stack.peek() << endl;

  cout << "Popped element: " << stack.pop() << endl;

  stack.push(18);
  cout << "Element at top: " << stack.peek() << endl;

  stack.kill();

  return 1;
}
