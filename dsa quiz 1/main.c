#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }

    int index = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[index]) {
            nums[++index] = nums[i];
        }
    }

    return index + 1;
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6};
    int numsSize = 10;

    int newLength = removeDuplicates(nums, numsSize);

    printf("New Length: %d\n", newLength);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}


