#include <stdio.h>
#include <stdlib.h>


int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

int main() {
    int nums[] = {4, 1, 2, 1, 2, 3, 4};
    int numsSize = 7;

    int single = singleNumber(nums, numsSize);

    printf("The single number is: %d\n", single);

    return 0;
}
