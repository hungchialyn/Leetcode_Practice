


typedef struct {
    int* prefix;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* numarr = malloc(sizeof(NumArray));
    numarr->prefix = malloc((numsSize + 1) * sizeof(int));
    numarr->prefix[0] = 0;
    for(int i = 1; i < numsSize + 1; i++){
        numarr->prefix[i] = nums[i - 1] + numarr->prefix[i - 1];
    }
    return numarr;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int sum = 0;
    sum = obj->prefix[right + 1] - obj->prefix[left];
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj->prefix);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
 */