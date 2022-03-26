#include <iostream>

#include "dbg.h"

using namespace std;

int search(int arr[], int size, int query);

int main(int argc, char *argv[]) {
  if (argv[1] == NULL) {
    log_err("Please provide an integer as the first argument.");
    return -1;
  }

  int query = atoi(argv[1]);

  int arr[] = {1, 2, 3, 4, 5};
  int size = *(&arr + 1) - arr;

  cout << "Index of " << query << ": " << search(arr, size, query) << endl;

  return 1;
}

int search(int arr[], int size, int query) {
  int low = 0;
  int high = size - 1;
  int mid;

  while (high >= low) {
    mid = low + ((high - low) / 2);

    if (arr[mid] == query) {
      return mid;
    } else {
      if (arr[mid] < query) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }

  return -1;
}
