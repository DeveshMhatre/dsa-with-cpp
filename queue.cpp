#include <iostream>

#include "dbg.h"

#define MAX_LEN 5

using namespace std;

class Queue {
private:
  int *arr;
  int size;
  int front;
  int rear;

  int *create() {
    int *array = (int *)malloc(sizeof(int) * size);
    check_mem(array);

    log_info("Queue created!");

    return array;

  error:
    exit(1);
  }

public:
  Queue(int capacity) {
    size = capacity;
    front = -1;
    rear = -1;

    arr = create();
  }

  int get_front() { return front; }

  int get_rear() { return rear; }

  int is_empty() {
    if (front == -1 && rear == -1) {
      return 1;
    }
    return 0;
  }

  int is_full() {
    if (rear == size - 1) {
      return 1;
    }
    return 0;
  }

  void enqueue(int element) {
    if (is_full() == 1) {
      log_err("Queue is full!");
      return;
    }
    if (is_empty() == 1) {
      front = 0;
    }
    rear += 1;
    arr[rear] = element;
  }

  int dequeue() {
    if (is_empty() == 1) {
      log_err("Queue is empty!");
      return -1;
    }

    int dequeued = arr[front];

    if (front == size - 1 && rear == size - 1) {
      front = -1;
      rear = -1;
      return dequeued;
    }

    front += 1;
    return dequeued;
  }

  int peek() {
    if (is_empty() == 1) {
      log_err("Queue is empty!");
      return -1;
    }
    return arr[front];
  }

  void kill() {
    check_mem(arr);
    free(arr);

    log_info("Queue freed!");

  error:
    exit(1);
  }
};

int main(int argc, char *argv[]) {
  Queue queue(MAX_LEN);

  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);
  queue.enqueue(5);

  cout << "Popped Element: " << queue.dequeue() << endl;
  cout << "Popped Element: " << queue.dequeue() << endl;
  cout << "Popped Element: " << queue.dequeue() << endl;
  cout << "Popped Element: " << queue.dequeue() << endl;
  cout << "Popped Element: " << queue.dequeue() << endl;

  queue.enqueue(1);

  cout << "Element at Front: " << queue.peek() << endl;

  queue.kill();

  return 1;
}
