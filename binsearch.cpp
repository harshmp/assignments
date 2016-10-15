#include<iostream>
#define N 10

int binarySearch(int input_list[], int L, int R, int search_num ){
  int index = 0;

  // The element was not found in the list
  if (L > R) {
    return -1;
  }

  int mid = (L + R) / 2;

  if (search_num > input_list[mid]) {
    // Search in the upper half
    index = binarySearch(input_list, mid + 1, R, search_num);
  }
  else if (search_num < input_list[mid]) {
    // Search in the lower half
    index = binarySearch(input_list, L, mid - 1, search_num);
  }
  else {
    // Element found
    index = mid;
  }
  return index;
}

int main() {
  int num_list[N] = { 3, 4, 6, 8, 9, 11, 34, 47, 99, 100 };

  int target_num = num_list[0];
  int target_num_index = 0;

  int start_index = 0, end_index = N - 1;

  for (size_t i = 0; i < 10; i++) {
    std::cout << num_list[i] << " ";
  }

  std::cout << " " << std::endl;

  std::cout << "What element do you want to search?" << std::endl;
  std::cin >> target_num;

  target_num_index = binarySearch(num_list, start_index, end_index, target_num);

  if (target_num_index >= 0) {
    std::cout << "The element was found at index: " << target_num_index << std::endl;
  }
  else{
    std::cout << "The element was not found." << std::endl;
  }
  return 0;
}
