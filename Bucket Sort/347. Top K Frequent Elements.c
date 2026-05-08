// 暴力解
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Pair {
    int num;
    int freq;
};
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = k;
    // 用 malloc，不能用 int res[k]
    int* res = (int*)malloc(sizeof(int) * k);
    
    struct Pair arr[numsSize];
    int unique = 0;

    for(int i = 0; i < numsSize; i++){
        int found = 0;

        for(int j = 0; j < unique; j++){
            if(nums[i] == arr[j].num){
                arr[j].freq++;
                found = 1;
                break;
            }
        }

        if(!found){
            arr[unique].num = nums[i];
            arr[unique].freq = 1;
            unique++;
        }
    }

    // 找 k 次最大頻率
    for(int i = 0; i < k; i++){
        int maxIdx = 0;

        for (int j = 1; j < unique; j++) {

            if (arr[j].freq > arr[maxIdx].freq) {
                maxIdx = j;
            }
        }

        res[i] = arr[maxIdx].num;

        // 標記已使用
        arr[maxIdx].freq = -1;
    }
    return res;
}