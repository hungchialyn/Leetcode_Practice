/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int* res=malloc(numsSize*sizeof(int));
    for(int i=0; i<numsSize; i++){
        res[i]=-1;
    }
    for(int i=0; i<numsSize; i++){
        for(int j=0; j<=nums[i]; j++){
            if((j|(j+1))==nums[i]) {
                printf("%d ", nums[i]);
                res[i]=j;
                break;
            }
        }
    }
    *returnSize=numsSize;
    return res;
}