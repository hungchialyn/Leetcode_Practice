/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    
    for(int i = 0; i < numsSize; i++){
        int idx = nums[i];
        if(idx < 0){
            idx = -idx;
        }
        idx--;
        if(nums[idx] > 0){
            nums[idx] = -nums[idx];
        }
    }
    *returnSize = 0;
    int* res = malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < 0){
            continue;
        }
        res[(*returnSize)++] = i + 1;
    }
    return res;
}