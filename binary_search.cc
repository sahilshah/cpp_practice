#include <stdio.h>

#include <iostream>
#include <vector>

bool BinarySearch(const std::vector<int>& numbers, int start, int end,
                  int key) {
  // Sanity check
  if ((start > end) || (start > numbers.size()) || (end > numbers.size())) {
    // problem; StatusOr? Exception?
    std::cout << "Problem!";
    return false;
  }

  // Terminating condition.
  if (start == end) {
    if (numbers[start] == key) {
      return true;
    } else {
      return false;
    }
  }

  if (numbers[start] <= key && key <= numbers[(start + end) / 2]) {
    // search start to start + end / 2
    // std::cout << "Searching indices " << start << " : " << (start + end) / 2
    //           << std::endl;
    return BinarySearch(numbers, start, (start + end) / 2, key);
  } else {
    // search start + end / 2 to end
    // std::cout << "Searching indices " << (start + end) / 2 + 1 << " : " << end
    //           << std::endl;
    return BinarySearch(numbers, (start + end) / 2 + 1, end, key);
  }
}

int main(int argc, char** argv) {
  std::vector<int> nums{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // std::for_each(nums.begin(), nums.end(), [](int num) {
  //   std::cout << num << std::endl;
  // });

  if (BinarySearch(nums, 0, nums.size() - 1, std::atoi(argv[1]))) {
    std::cout << "Found!" << std::endl;
  } else {
    std::cout << "Not Found!" << std::endl;
  }

  return 0;
}