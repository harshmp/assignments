#include <iostream>
#include <cstdlib>
#include <omp.h>
#define N 10 // 10 million elements (not distinct), change it to test the time taken
using namespace std;

//int MAX_THREADS;
int partition(int *input_list, int low, int high){
    int pivot = input_list[high];
    int temp = 0;
    int i = low;
    for(int j = low; j < high; j++) {
        if(input_list[j] <= pivot){
            temp = input_list[i];
            input_list[i] = input_list[j];
            input_list[j] = temp;
            i = i + 1;
        }
    }
    temp = input_list[i];
    input_list[i] = input_list[high];
    input_list[high] = temp;
    return i;
}

void quicksort(int *input_list, int low, int high) {
  int p = 0;
  if (low < high) {
    p = partition(input_list, low, high);
    #pragma omp parallel sections
    {
      #pragma omp section
      {
        quicksort(input_list, low, p - 1);
      }
      #pragma omp section
      {
        quicksort(input_list, p + 1, high);
      }
    }
  }
}
int main() {
  int* num_list = new int[N];
  int start_index = 0, end_index = N - 1;
  srand(time(NULL));
  // Generate an array of N random numbers
  for (int i = 0; i < N; i++) {
    num_list[i] = rand()%N;
  }
  omp_set_nested(true);
  //MAX_THREADS = omp_get_max_threads();
  quicksort(num_list, start_index, end_index);

  return 0;
}
