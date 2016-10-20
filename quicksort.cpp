#include <iostream>
#include <omp.h>
#define N 10
using namespace std;

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *input_list, int start, int end) {
  int pivot = input_list[end];
  int i = start;
  int temp = 0;

  for (int current = start; current < end; current++) {
    if (input_list[current] <= pivot) {
      swap(input_list[i], input_list[current]);
      i++;
    }
  }

  swap(input_list[i], input_list[end]);
  return i;
}

void quicksort(int *input_list, int start, int end) {
  int pivot_index = 0;
  if (start < end) {
    pivot_index = partition(input_list, start, end);
    #pragma omp parallel sections
    {
      #pragma omp section
      {
        quicksort(input_list, start, pivot_index - 1);
      }
      #pragma omp section
      {
        quicksort(input_list, pivot_index + 1, end);
      }
    }
  }

}

int main() {
  int num_list[] = { 10, 2, 4, 5, 1, 7, 9, 8, 3, 6 };
  int start_index = 0, end_index = N - 1;

  cout << "Before quicksort:\n";
  for (int i = 0; i < N; i++) {
    cout << num_list[i] << " ";
  }
  cout << endl;

  quicksort(num_list, start_index, end_index);

  cout << "After quicksort:\n";
  for (int i = 0; i < N; i++) {
    cout << num_list[i] << " ";
  }
  cout << endl;

  return 0;
}
