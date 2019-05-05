/*
 * @lc app=leetcode id=198 lang=c
 *
 * [198] House Robber
 */


int rob(int* nums, int numsSize){
    if(nums == 0){
        return 0;
    }
    if(numsSize == 1){
        return *nums;
    }if(numsSize == 1){
        return (*nums > *(nums+1) ? *nums : *(nums + 1));
    }
    int sum1 = *nums + rob(nums+2, numsSize -2);
    int sum2 = rob(nums + 1, numsSize-1);
    return (sum1 > sum2) ? sum1 : sum2;

}
/*
https://leetcode.com/submissions/detail/226865587/
56 / 69 test cases passed.
Time Limit Exceeded
Last executed input:
[114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240]
 */
