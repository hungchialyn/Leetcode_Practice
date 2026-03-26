int minOperations(int* nums, int numsSize, int k) {
    long ans = 0;
    ans = (1L<<k) - 1;
    long bit = 0;
    int res = 0;
    for(int i = numsSize-1; i >= 0; i--){
        bit |= 1L<<(nums[i]-1);
        res++;
        if((bit&ans) == ans){
            return res;
        }
    }
    return -1;
}


/*
****需要注意： 
1<<k代表的是int型態的1往左移k格，
在k>32的情況下會爆掉，
解法是用long型態的1往左移k格，
以符合變數形態。
ans = 1L<<k - 1;
*/