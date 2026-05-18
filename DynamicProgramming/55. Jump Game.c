bool canJump(int* nums, int numsSize) {
    bool dp[numsSize];

    for(int i = 0; i < numsSize; i++){
        dp[i] = false;
    }
    dp[0] = true;

    for(int i = 0; i < numsSize-1; i++){
        if(dp[i]){  //dp[i]會被踩到=true
            int jump = nums[i];
            for(int j = 0; j < jump; j++){
                // printf("%d %d\n", i, j);
                if(i+j+1 > numsSize-1){
                    continue;
                }else{
                    dp[i+j+1] = true;
                }
            }
        }
    }

    // for(int i = 0; i < numsSize; i++){
    //     printf("%d ", dp[i]);
    // }

    return dp[numsSize-1];
}