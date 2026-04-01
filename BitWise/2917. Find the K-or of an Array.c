int findKOr(int* nums, int numsSize, int k) {
    int res = 0;
    for(int i = 0; i < 31; i++){
        int cnt = 0;
        for(int j = 0; j < numsSize; j++){
            if(nums[j]&1){
                cnt++;
            }
            nums[j]>>=1;
        }
        if(cnt>=k){
            res |= 1<<i;
        }
    }
    return res;
}