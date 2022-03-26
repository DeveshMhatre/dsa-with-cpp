#include <iostream>

#include "dbg.h"

#define MAX_LEN 5

using namespace std;

class CircularQueue {
private:
  int *arr;
  int size;
  int front;
  int rear;

  int *create() {
    int *array = (int *)malloc(sizeof(int) * size);
    check_mem(array);

    return array;
  error:
    exit(1);
  }

public:
  CircularQueue(int capacity) {
    size = capacity;
    front = -1;
    rear = -1;
    arr = create();

    log_info("Circular Queue created!");
  }

  int get_size() { return size; }

  int is_empty() {
    if (front == -1 && rear == -1) {
      return 1;
    }
    return 0;
  }

  int is_full() {
    if ((front == 0 && rear == size - 1) || (rear == front - 1)) {
      return 1;
    }
    return 0;
  }

  void enqueue(int element) {
    if (is_full() == 1) {
      log_err("Circular Queue is full!");
      return;
    }

    /* Point front to first element if queue is empty */
    if (is_empty() == 1) {
      front += 1;
    }

    /* Insert element at the first index if rear is pointing to last index */
    if (rear == size - 1) {
      rear = 0;
    } else {
      rear += 1;
    }

    arr[rear] = element;
  }

  int dequeue() {
    if (is_empty() == 1) {
      log_err("Circular Queue is empty!");
      return -1;
    }

    int dequeued = arr[front];

    /* Reset front and rear to -1 if both are pointing to the same index (last
     * element) */
    if (front == rear) {
      front = -1;
      rear = -1;
      return dequeued;
    }

    /* Point front to the first index if it is pointing to the last index */
    if (front == size - 1) {
      front = 0;
    } else {
      front += 1;
    }

    return dequeued;
  }

  int peek() {
    if (is_empty() == 1) {
      log_err("Circular Queue is empty!");
      return -1;
    }

    return arr[front];
  }

  void kill() {
    check_mem(arr);
    free(arr);

    log_info("Circular Queue freed!");

  error:
    exit(1);
  }
};

int main(int argc, char *argv[]) {
  CircularQueue queue(MAX_LEN);

  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);
  queue.enqueue(5);

  cout << queue.dequeue() << endl;
  cout << queue.dequeue() << endl;
  cout << queue.dequeue() << endl;
  cout << queue.dequeue() << endl;

  cout << queue.peek() << endl;

  queue.enqueue(8);

  cout << queue.dequeue() << endl;

  cout << queue.peek() << endl;

  cout << queue.dequeue() << endl;

  cout << queue.peek() << endl;

  queue.kill();

  return 1;
}
