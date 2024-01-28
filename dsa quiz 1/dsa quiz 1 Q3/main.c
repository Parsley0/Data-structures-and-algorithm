#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool containsDuplicate(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return true;  // Found a duplicate
            }
        }
    }
    return false;  // No duplicates found
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int numsSize = 8;

    bool hasDuplicate = containsDuplicate(nums, numsSize);

    if (hasDuplicate) {
        printf("The array contains duplicates.\n");
    } else {
        printf("The array does not contain duplicates.\n");
    }

    return 0;
}


