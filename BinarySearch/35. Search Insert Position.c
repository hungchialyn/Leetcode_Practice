int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize-1;

    while(left < right){
        int middle = nums[(left+right) / 2];

        if(target == middle){
            return (left+right) / 2;
        }

        if(target < middle){
            right = (left+right) / 2;
        }else{
            left = (left+right) / 2 + 1;
        }
    }
    if(nums[left]>=target){
        return left;
    }
    return left+1;
}

//20260605
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] < target){
            left = mid + 1;
        }
        if(nums[mid] > target){
            right = mid - 1;
        }
    }
    
    return left;
}