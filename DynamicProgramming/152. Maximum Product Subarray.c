int max3(int n, int p_max, int p_min){
    int m = n > p_max ? n : p_max;
    return m > p_min ? m : p_min;
}
int min3(int n, int p_max, int p_min){
    int m = n > p_max ? p_max : n;
    return m > p_min ? p_min : m;
}

int maxProduct(int* nums, int numsSize) {
    int max = nums[0];
    int current_max = nums[0];
    int current_min = nums[0];
    for(int i = 1; i < numsSize; i++){
        int n = nums[i];
        int prev_max = current_max; //保存舊值
        int prev_min = current_min;

        current_max = max3(n, prev_max*n, prev_min*n);
        current_min = min3(n, prev_max*n, prev_min*n);

        if(current_max > max){
            max = current_max;
        }
    }
    return max;
}