int digitsum(int num){
    int sum = 0;
    while(num > 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int minElement(int* nums, int numsSize) {
    int min = 10000;
    for(int i = 0; i < numsSize; i++){
        int num = digitsum(nums[i]);
        if(num < min){
            min = num;
        }
    }
    return min;
}