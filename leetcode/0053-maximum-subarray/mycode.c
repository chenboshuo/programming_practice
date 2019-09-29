#include<limits.h>

int max_subsum(const int* nums, int left, int right){
    if(left == right){ // base case
        return nums[left];
    }

    int center = (left + right)/2;
    int max_left_sum = max_subsum(nums, left, center);
    int max_right_sum = max_subsum(nums, center+1, right);

    int max_left_border_sum = INT_MIN,left_boder_sum=0;
    for(int i = center; i>=left; --i){
        left_boder_sum += nums[i];
        if(left_boder_sum > max_left_border_sum){
            max_left_border_sum = left_boder_sum;
        }
    }

    int max_right_border_sum = INT_MIN,right_boder_sum=0;
    for(int i = center+1; i<=right; ++i){
        right_boder_sum += nums[i];
        if(right_boder_sum > max_right_border_sum){
            max_right_border_sum = right_boder_sum;
        }
    }

    int max = max_right_border_sum + max_left_border_sum;
    if(max < max_left_sum){
        max = max_left_sum;
    }
    if(max < max_right_sum){
        max = max_right_sum;
    }

    return max;
}

int maxSubArray(int* nums, int numsSize){
    return max_subsum(nums, 0, numsSize-1);
}

// https://leetcode.com/submissions/detail/265301189/
// Runtime: 8 ms, faster than 68.95% of C online submissions for Maximum Subarray.
// Memory Usage: 7.5 MB, less than 94.74% of C online submissions for Maximum Subarray.
