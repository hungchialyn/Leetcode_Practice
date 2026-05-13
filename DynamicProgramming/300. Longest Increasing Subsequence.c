//暴力解

int lengthOfLIS(int* nums, int numsSize) {
    int res[numsSize];
    int ans = 1;

    for(int i = 0; i < numsSize; i++){
        res[i] = 1;
    }

    for(int i = 1; i < numsSize; i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                if(res[j] +1 > res[i]){
                    res[i] = res[j] + 1;
                }
            }
        }

        if(res[i] > ans){
            ans = res[i];
        }
    }


    return ans;
}